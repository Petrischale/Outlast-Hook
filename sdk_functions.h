#pragma once
#include "engine.h"

namespace functions {
	extern UObject* K2_GetActorLocation_FN;

	extern UObject* K2_GetActorRotation_FN;

	extern UObject* K2_DrawText_FN;

	extern UObject* K2_DrawLine_FN;

	extern UObject* K2_GetPawn_FN;

	extern UObject* LineOfSightTo_FN;

	extern UObject* ProjectWorldLocationToScreen_FN;

	extern UObject* GetActorBounds_FN;

	extern UObject* IsArmWreslingRoundInProgress_FN;

	extern UObject* GetCursorPosition_FN;

	extern UObject* GetGamePlayerName_FN;

	extern UObject* GetLocallyWatchedPanel_FN;

	extern UObject* IsPanelActive_FN;

	extern UObject* IsVisible_FN;

	void init();
}
