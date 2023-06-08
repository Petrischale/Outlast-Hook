#include "sdk.h"
#include "fnamepool.h"
#include "sdk_functions.h"

extern bool bClick;
extern bool NVOn;

extern UObject* engine_font;
extern UWorld* world;
extern TUObjectArray* objectArray;

extern UObject* leaveChair;
extern UObject* rbnpc;
extern UObject* rbplayer;
extern UObject* rbpickup;
extern UObject* rbposter;
extern UObject* armwreslingtable;
extern URBArmWreslingPanelComponent* curr_armwresling_component;

void RenderText(UCanvas* canvas, FVector2D position, std::string text, FLinearColor color);
void NpcESP(AActor* actor, APlayerController* controller, UCanvas* canvas);
void PlayerESP(AActor* actor, APlayerController* controller, UCanvas* canvas);
void ItemESP(AActor* actor, APlayerController* controller, UCanvas* canvas);