#include "features.h"
#include <chrono>
#include <thread>
#include <string>

UObject* engine_font = 0x0;
UWorld* world = 0x0;
TUObjectArray* objectArray = 0x0;
UObject* leaveChair = 0x0;
UObject* rbnpc = 0x0;
UObject* rbplayer = 0x0;
UObject* rbpickup = 0x0;
UObject* rbposter = 0x0;
UObject* armwreslingtable = 0x0;
URBArmWreslingPanelComponent* curr_armwresling_component = 0x0;


std::pair<std::string, FLinearColor> find_valid_target_text(AActor* actor) {
    if (actor->GetName().find("LockPick") != std::string::npos) return std::make_pair(std::string("LockPick"), FLinearColor{ 1.f, 1.f, 1.f, 1.f });
    if (actor->GetName().find("Weapon") != std::string::npos) return std::make_pair(std::string("Weapon"), FLinearColor{ 1.f, 1.f, 1.f, 1.f });

    if (actor->GetName().find("SmallBattery") != std::string::npos) return std::make_pair(std::string("Small Battery"), FLinearColor{ 1.000000f , 0.882353f, 0.098039f, 1.f });
    if (actor->GetName().find("Battery") != std::string::npos) return std::make_pair(std::string("Large Battery"), FLinearColor{ 1.000000f , 0.882353f, 0.098039f, 1.f });
    if (actor->GetName().find("SkillChargeItem") != std::string::npos) return std::make_pair(std::string("Rig Recharge"), FLinearColor{ 1.000000f , 0.882353f, 0.098039f, 1.f });

    if (actor->GetName().find("ReviveSyringe") != std::string::npos) return std::make_pair(std::string("Revive Syringe"), FLinearColor{ 0.235294f , 0.705882f, 0.294118f, 1.f });
    if (actor->GetName().find("PsychosisAntidote") != std::string::npos) return std::make_pair(std::string("Antidote"), FLinearColor{ 0.235294f , 0.705882f, 0.294118f, 1.f });
    if (actor->GetName().find("TempHealthGain-Consumable") != std::string::npos) return std::make_pair(std::string("Small Medicine"), FLinearColor{ 0.235294f , 0.705882f, 0.294118f, 1.f });
    if (actor->GetName().find("HealthGain-Consumable") != std::string::npos) return std::make_pair(std::string("Large Medicine"), FLinearColor{ 0.235294f , 0.705882f, 0.294118f, 1.f });

    if (actor->GetName().find("QuestItem") != std::string::npos) return std::make_pair(std::string("Quest Item"), FLinearColor{ 0.568627f , 0.117647f, 0.705882f, 1.f });
    if (actor->GetName().find("Poster") != std::string::npos) return std::make_pair(std::string("Poster"), FLinearColor{ 0.568627f , 0.117647f, 0.705882f, 1.f });
    if (actor->GetName().find("Propaganda") != std::string::npos) return std::make_pair(std::string("Poster"), FLinearColor{ 0.568627f , 0.117647f, 0.705882f, 1.f });
    if (actor->GetName().find("CollectibleDocument") != std::string::npos) return std::make_pair(std::string("Document"), FLinearColor{ 0.568627f , 0.117647f, 0.705882f, 1.f });
    return std::make_pair(std::string("ERROR"), FLinearColor{ 0.f, 0.f, 0.f, 0.f });
}

constexpr const char* ENPCTypeToString(ENPCType e) noexcept {
    switch (e) {
    case ENPCType::Grunt: return "Grunt";
    case ENPCType::Ambient: return "Ambient";
    case ENPCType::BigGrunt: return "Big Grunt";
    case ENPCType::PitcherSniper: return "Pitcher Sniper";
    case ENPCType::SleeperScreamer: return "Screamer";
    case ENPCType::Pouncer: return "Pouncer";
    case ENPCType::Pusher: return "Pusher";
    case ENPCType::GroundPitcher: return "Ground Pitcher";
    case ENPCType::Berserker: return "Berserker";
    case ENPCType::Imposter: return "Imposter";
    case ENPCType::NightHunter: return "Night Hunter";
    case ENPCType::Spectre: return "Spectre";
    case ENPCType::Gooseberry: return "Gooseberry";
    case ENPCType::Coyle: return "Coyle";
    case ENPCType::MAX: return "MAX";
    }
}

void RenderText(UCanvas* canvas, FVector2D position, std::string text, FLinearColor color) {
    std::wstring ws(text.size(), L' ');
#pragma warning(suppress : 4996)
    ws.resize(std::mbstowcs(&ws[0], text.c_str(), text.size()));
    canvas->K2_DrawText(engine_font, ws.c_str(), position, { 1.f,1.f }, color, 1.f, { 0.0f, 0.0f, 0.0f, 0.f }, { 0.0f, 0.0f }, true, false, false, color);
}

void RenderLine(UCanvas* canvas, FVector2D startPosition, FVector2D endPosition, float thickness, FLinearColor color) {
    canvas->K2_DrawLine(startPosition, endPosition, thickness, color);
}

void RenderBox(UCanvas* canvas, FVector2D topLeft, FVector2D downRight, FLinearColor color, float thickness) {
    auto h = downRight.y - topLeft.y;
    auto w = downRight.x - topLeft.x;
    auto downLeftFinal = FVector2D{ topLeft.x, downRight.y };
    auto topRightFinal = FVector2D{ downRight.x, topLeft.y };
    RenderLine(canvas, topLeft, { topLeft.x, topLeft.y + h * 1 }, thickness, color);
    RenderLine(canvas, topLeft, { topLeft.x + w * 1, topLeft.y }, thickness, color);
    RenderLine(canvas, downRight, { downRight.x, downRight.y - h * 1 }, thickness, color);
    RenderLine(canvas, downRight, { downRight.x - w * 1, downRight.y }, thickness, color);
    RenderLine(canvas, downLeftFinal, { downLeftFinal.x, downLeftFinal.y - h * 1 }, thickness, color);
    RenderLine(canvas, downLeftFinal, { downLeftFinal.x + w * 1, downLeftFinal.y }, thickness, color);
    RenderLine(canvas, topRightFinal, { topRightFinal.x, topRightFinal.y + h * 1 }, thickness, color);
    RenderLine(canvas, topRightFinal, { topRightFinal.x - w * 1, topRightFinal.y }, thickness, color);
}

void NpcESP(AActor* actor, APlayerController* controller, UCanvas* canvas) {
    auto npc_type = static_cast<int>(((ARBNPC*)actor)->NPCType);
    if (npc_type == 12 || npc_type == 13 || npc_type == 16 || npc_type == 17) return;
    bool is_visible = controller->LineOfSightTo(actor, { 0.0f, 0.0f, 0.0f }, false);
    FVector location;
    FVector BoxExtent;
    actor->GetActorBounds(true, location, BoxExtent, false);
    auto rotation = actor->K2_GetActorRotation();
    FVector foot_location = { location.X, location.Y, location.Z + (BoxExtent.Z) };
    FVector head_location = { location.X, location.Y, location.Z - (BoxExtent.Z) };
    FVector2D head_pos, foot_pos;
    if (controller->ProjectWorldLocationToScreen(foot_location, foot_pos, false) && controller->ProjectWorldLocationToScreen(head_location, head_pos, false)) {
        const float h = abs(foot_pos.y - head_pos.y);
        const float w = h;
        FVector2D top = { head_pos.x - w * 0.25f, head_pos.y };
        FVector2D bottom = { head_pos.x + w * 0.25f, foot_pos.y };
        RenderBox(canvas, top, bottom, is_visible ? FLinearColor{ 0.501961f, 0.000000f, 0.000000f, 1.f } : FLinearColor{ 0.501961f , 0.000000f, 0.000000f, 1.f }, 1.f);
    }
    FVector2D w2s_result;
    if (controller->ProjectWorldLocationToScreen(location, w2s_result, false)) {
        RenderText(canvas, w2s_result, ENPCTypeToString(((ARBNPC*)actor)->NPCType), { 1.000000f , 0.980392f, 0.784314f, 1.f });
    }
}

void PlayerESP(AActor* actor, APlayerController* controller, UCanvas* canvas) {
    //Infinite Stamina
    if (actor == controller->Character) {
        //printf("Stamina: [%f]\n", ((ARBPlayer*)actor)->stamina);
        //((ARBPlayer*)actor)->stamina = 125.0f;
        return; //No need to draw box for yourself
    }
    bool is_visible = controller->LineOfSightTo(actor, { 0.0f, 0.0f, 0.0f }, false);
    FVector location;
    FVector BoxExtent;
    actor->GetActorBounds(true, location, BoxExtent, false);
    auto rotation = actor->K2_GetActorRotation();
    FVector foot_location = { location.X, location.Y, location.Z + (BoxExtent.Z) };
    FVector head_location = { location.X, location.Y, location.Z - (BoxExtent.Z) };
    FVector2D head_pos, foot_pos;
    if (controller->ProjectWorldLocationToScreen(foot_location, foot_pos, false) && controller->ProjectWorldLocationToScreen(head_location, head_pos, false)) {
        const float h = abs(foot_pos.y - head_pos.y);
        const float w = h;
        FVector2D top = { head_pos.x - w * 0.25f, head_pos.y };
        FVector2D bottom = { head_pos.x + w * 0.25f, foot_pos.y };
        RenderBox(canvas, top, bottom, is_visible ? FLinearColor{ 0.000000f, 0.000000f, 0.501961f, 1.f } : FLinearColor{ 0.000000f , 0.000000f, 0.501961f, 1.f }, 1.f);
    }
    auto name = ((ARBPlayer*)actor)->GetGamePlayerName();
    if (name.is_valid()) {
        FVector2D w2s_result;
        if (controller->ProjectWorldLocationToScreen(location, w2s_result, false)) {
            RenderText(canvas, w2s_result, name.to_string(), { 1.000000f , 0.980392f, 0.784314f, 1.f });
        }
    }
}

void ItemESP(AActor* actor, APlayerController* controller, UCanvas* canvas) {
    auto name = find_valid_target_text(actor);
    if (name.first == "ERROR") {
        return;
    }
    //if (name.first != "Quest Item" && name.first != "Document" && name.first != "Poster") {
    //    auto local_player = controller->K2_GetPawn();
    //    if (!local_player) return;
    //    const auto myLocation = local_player->K2_GetActorLocation();
    //    if (!actor) return;
    //    if (((ARBPickup*)actor)->bHasBeenPickedUp == true) return;
    //    const FVector item_location = actor->K2_GetActorLocation();
    //    const float dist = myLocation.DistTo(item_location) * 0.01f;
    //    if (dist > 35.0f) return;
    //    FVector location, BoxExtent;
    //    actor->GetActorBounds(false, location, BoxExtent, false);
    //    FVector2D w2s_result;
    //    std::string name_dist = name.first + " [" + std::to_string((int)dist) + "m]";
    //    if (controller->ProjectWorldLocationToScreen(location, w2s_result, false)) {
    //        RenderText(canvas, w2s_result, name_dist, name.second);
    //    }
    //    return;
    //}
    auto local_player = controller->K2_GetPawn();
    if (!local_player) return;
    const auto myLocation = local_player->K2_GetActorLocation();
    if (!actor) return;
    if (((ARBPickup*)actor)->bHasBeenPickedUp == true) return;
    const FVector item_location = actor->K2_GetActorLocation();
    const float dist = myLocation.DistTo(item_location) * 0.01f;
    if ((name.first != "Quest Item" && name.first != "Document" && name.first != "Poster") && dist > 35.0f) return;
    FVector location, BoxExtent;
    actor->GetActorBounds(false, location, BoxExtent, false);
    FVector2D w2s_result;
    std::string name_dist = name.first + " [" + std::to_string((int)dist) + "m]";
    if (controller->ProjectWorldLocationToScreen(location, w2s_result, false)) {
        RenderText(canvas, w2s_result, name_dist, name.second);
    }
    //FVector location, BoxExtent;    
    //actor->GetActorBounds(false, location, BoxExtent, false);
    //FVector2D w2s_result;
    //if (controller->ProjectWorldLocationToScreen(location, w2s_result, false)) {
    //    RenderText(canvas, w2s_result, name.first, name.second);
    //}
}
