#include "main.h"
#include "features.h"
#include "patternscan.h"
#include "Minhook/include/MinHook.h"
#include <chrono>
#include <thread>

char worldSig[] = "\x48\x8b\x05\x00\x00\x00\x00\x48\x8d\x95\x00\x00\x00\x00\x48\x8b\x48";
char worldMask[] = "xxx????xxx????xxx";

char objSig[] = "\x48\x8d\x05\x00\x00\x00\x00\xc7\x05\x00\x00\x00\x00\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8d\x05\x00\x00\x00\x00\x48\x83\xc4";
char objMask[] = "xxx????xx????????xxx????xxx????xxx";

char nameSig[] = "\x48\x8d\x0d\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x48\x8d\x85\x00\x00\x00\x00\x48\x83\xc3\x00\x48\x3b\xd8\x75\x00\x48\x83\x7c\x24";
char nameMask[] = "xxx????x????xxx????xxx?xxxx?xxxx";

bool bClick = false;
using Clock = std::chrono::steady_clock;
std::chrono::time_point<std::chrono::steady_clock> start, now;
std::chrono::milliseconds duration;

using post_render_fn = void(__thiscall*)(UGameViewportClient*, UCanvas*);
using process_event_fn = void(__thiscall*)(UObject*, UObject*, void* parms);
post_render_fn post_render_original = 0;
process_event_fn process_event_original = 0;

void sigscan() {
    uintptr_t worldAddr = Aobs(worldSig, worldMask, (uintptr_t)g_BaseModule.lpBaseOfDll, (uintptr_t)g_BaseModule.lpBaseOfDll + (uintptr_t)g_BaseModule.SizeOfImage);
    auto worldOffset = *reinterpret_cast<uint32_t*>(worldAddr + 3);
    worldAddr = worldAddr + 7 + worldOffset;
    world = *(UWorld**)(worldAddr);

    uintptr_t objAddr = Aobs(objSig, objMask, (uintptr_t)g_BaseModule.lpBaseOfDll, (uintptr_t)g_BaseModule.lpBaseOfDll + (uintptr_t)g_BaseModule.SizeOfImage);
    auto objOffset = *reinterpret_cast<uint32_t*>(objAddr + 3);
    objAddr = objAddr + 7 + objOffset;
    objectArray = (TUObjectArray*)(objAddr);

    uintptr_t nameAddr = Aobs(nameSig, nameMask, (uintptr_t)g_BaseModule.lpBaseOfDll, (uintptr_t)g_BaseModule.lpBaseOfDll + (uintptr_t)g_BaseModule.SizeOfImage);
    auto nameOffset = *reinterpret_cast<uint32_t*>(nameAddr + 3);
    nameAddr = nameAddr + 7 + nameOffset;
    NamePool = (FNamePool*)(nameAddr);
}

bool rbposter_corr = false;

void post_render_hook(UGameViewportClient* viewport_client, UCanvas* canvas) {
    RenderText(canvas, { 50.f, 15.f }, "Fellner Hook", { 1.f,0.0f, 0.f,1.f });
    auto world = viewport_client->World;
    auto game_instance = viewport_client->GameInstance;
    if (!game_instance->LocalPlayers.Count) return post_render_original(viewport_client, canvas);
    auto local_player = game_instance->LocalPlayers.Objects[0];
    if (!local_player) return post_render_original(viewport_client, canvas);
    auto controller = local_player->PlayerController;
    if(!world->Levels.Count) return post_render_original(viewport_client, canvas);
    auto levels = world->Levels;
    for (int i = 0; i < levels.Count; i++) {
        auto curr_level = levels.Objects[i];
        if (curr_level) {
            for (int j = 0; j < curr_level->NearActors.Count; j++) {
                auto actor = curr_level->NearActors.Objects[j];
                //Auto Clicker ArmWrestlingTable
                if (actor && actor->IsA(armwreslingtable)) {
                    curr_armwresling_component = ((ARBArmWreslingTable*)actor)->GetLocallyWatchedPanel();
                    if (curr_armwresling_component && curr_armwresling_component->IsArmWreslingRoundInProgress()) {
                        const auto cursor_position = curr_armwresling_component->GetCursorPosition();
                        if (cursor_position > 0.1f) {
                            const auto zone_end = 1.f - curr_armwresling_component->SuccessZoneOffset;
                            if (zone_end >= cursor_position && zone_end - cursor_position <= 0.03f) {
                                bClick = true;
                                continue;
                            }
                        }
                    }
                }
                //NPC ESP
                if (actor && actor->RootComponent && actor->IsA(rbnpc)) {
                    NpcESP(actor, controller, canvas);
                    continue;
                }
                //Player ESP
                if (actor && actor->RootComponent && actor->IsA(rbplayer)) {
                    PlayerESP(actor, controller, canvas);
                    continue;
                }
                //Item ESP
                if (actor && actor->RootComponent && actor->IsA(rbpickup)) {
                    ItemESP(actor, controller, canvas);
                    continue;
                }
                if (actor && actor->RootComponent && actor->IsA(rbposter)) {
                    if (actor->RootComponent->IsVisible() == true) {
                        ItemESP(actor, controller, canvas);
                    }
                    continue;
                }
            }
        }
    }
    post_render_original(viewport_client, canvas);
}

bool updateRBPoster = false;

void process_event_hook(UObject* caller, UObject* fn, void* parms) {
    if (fn == leaveChair) {
        updateRBPoster = true;
    }
    process_event_original(caller, fn, parms);
}

void init() {
    auto game_instance = world->OwningGameInstance;
    auto local_player = game_instance->LocalPlayers.Objects[0];
    auto viewport_client = local_player->ViewportClient;
    void** VFTable = viewport_client->VFTable;
    functions::init();
    engine_font = objectArray->FindObject("Font Roboto.Roboto");
    rbnpc = objectArray->FindObject("Class OPP.RBNPC");
    rbplayer = objectArray->FindObject("Class OPP.RBPlayer");
    rbpickup = objectArray->FindObject("Class OPP.RBPickup");
    rbposter = objectArray->FindObject("BlueprintGeneratedClass Base_PropagandaPoster_BP.Base_PropagandaPoster_BP_C");
    armwreslingtable = objectArray->FindObject("Class OPP.RBArmWreslingTable");
    leaveChair = objectArray->FindObject("Function SASChair_ChairAnimBP.SASChair_ChairAnimBP_C.AnimNotify_ChairLeave");
    //auto fonts = objectArray->FindObjectsByString("Font");
    //for (auto elem : fonts) {
    //    printf("Font: [%s]\n", elem->GetFullName().c_str());
    //}


    MH_Initialize();
    if (MH_CreateHook(VFTable[post_render_index], &post_render_hook, reinterpret_cast<void**>(&post_render_original)) != MH_OK) {
        throw std::runtime_error(("failed to hook post_render"));
    }
    MH_EnableHook(VFTable[post_render_index]);
    if (MH_CreateHook(VFTable[process_event_index], &process_event_hook, reinterpret_cast<void**>(&process_event_original)) != MH_OK) {
        throw std::runtime_error(("failed to hook process_event"));
    }
    MH_EnableHook(VFTable[process_event_index]);

    printf("Init done!\n");
}

void Run(HMODULE hMODULE) {
    FILE* fp = nullptr;
    AllocConsole();
    freopen_s(&fp, "CONOUT$", "w", stdout);
    K32GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(nullptr), &g_BaseModule, sizeof(MODULEINFO));
    bool welcomed = false;
    INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    start = Clock::now();
    while (true) {
        if (!welcomed) {
            std::cout << "Welcome to Fellner Hook - The best Ware in Town!" << std::endl;
            welcomed = true;
            sigscan();
            init();
        }
        if (bClick) {
            now = Clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
            if (duration.count() >= 5) {
                input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(1, &input, sizeof(INPUT));
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
                input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(1, &input, sizeof(INPUT));
                start = std::chrono::steady_clock::now();
                bClick = false;
            }
        }
        if (updateRBPoster) {
            printf("Updating!\n");
            if (!rbposter) rbposter = objectArray->FindObject("BlueprintGeneratedClass Base_PropagandaPoster_BP.Base_PropagandaPoster_BP_C");
            if (rbposter) updateRBPoster = false;
        }
    }
}
