#include "sdk_functions.h"

extern TUObjectArray* objectArray;

namespace functions {
	UObject* K2_GetActorLocation_FN = 0;

	UObject* K2_GetActorRotation_FN = 0;

	UObject* K2_DrawText_FN = 0;

	UObject* K2_DrawLine_FN = 0;

	UObject* K2_GetPawn_FN = 0;

	UObject* LineOfSightTo_FN = 0;

	UObject* ProjectWorldLocationToScreen_FN = 0;

	UObject* GetActorBounds_FN = 0;

	UObject* IsArmWreslingRoundInProgress_FN = 0;

	UObject* GetCursorPosition_FN = 0;

	UObject* GetGamePlayerName_FN = 0;

	UObject* GetLocallyWatchedPanel_FN = 0;

	UObject* IsPanelActive_FN = 0;

	void init() {
		K2_GetActorLocation_FN = objectArray->FindObject("Function Engine.Actor.K2_GetActorLocation");

		K2_GetActorRotation_FN = objectArray->FindObject("Function Engine.Actor.K2_GetActorRotation");

		K2_DrawText_FN = objectArray->FindObject("Function Engine.Canvas.K2_DrawText");

		K2_DrawLine_FN = objectArray->FindObject("Function Engine.Canvas.K2_DrawLine");

		K2_GetPawn_FN = objectArray->FindObject("Function Engine.Controller.K2_GetPawn");

		LineOfSightTo_FN = objectArray->FindObject("Function Engine.Controller.LineOfSightTo");

		ProjectWorldLocationToScreen_FN = objectArray->FindObject("Function Engine.PlayerController.ProjectWorldLocationToScreen");

		GetActorBounds_FN = objectArray->FindObject("Function Engine.Actor.GetActorBounds");

		IsArmWreslingRoundInProgress_FN = objectArray->FindObject("Function OPP.RBArmWreslingPanelComponent.IsArmWreslingRoundInProgress");

		GetCursorPosition_FN = objectArray->FindObject("Function OPP.RBArmWreslingPanelComponent.GetCursorPosition");

		GetGamePlayerName_FN = objectArray->FindObject("Function OPP.RBPlayer.GetGamePlayerName");

		GetLocallyWatchedPanel_FN = objectArray->FindObject("Function OPP.RBArmWreslingTable.GetLocallyWatchedPanel");

		IsPanelActive_FN = objectArray->FindObject("Function OPP.RBInteractiblePanelComponent.IsPanelActive");
	}
}
