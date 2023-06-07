#include "sdk.h"
#include "sdk_functions.h"

FRotator AActor::K2_GetActorRotation() {
    struct {
        FRotator return_value;
    } parms;

    ProcessEvent(functions::K2_GetActorRotation_FN, &parms);
    return parms.return_value;
}

FVector AActor::K2_GetActorLocation() {
    struct {
        FVector return_value;
    } parms;

    ProcessEvent(functions::K2_GetActorLocation_FN, &parms);
    return parms.return_value;
}

void UCanvas::K2_DrawText(UObject* RenderFont, FString RenderText, FVector2D ScreenPosition, FVector2D Scale, FLinearColor RenderColor, float Kerning, FLinearColor ShadowColor, FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, FLinearColor OutlineColor) {
    struct {
        UObject* RenderFont;
        FString RenderText;
        FVector2D ScreenPosition;
        FVector2D Scale;
        FLinearColor RenderColor;
        float Kerning;
        FLinearColor ShadowColor;
        FVector2D ShadowOffset;
        bool bCentreX;
        bool bCentreY;
        bool bOutlined;
        FLinearColor OutlineColor;
    }params{};

    params.RenderFont = RenderFont;
    params.RenderText = RenderText;
    params.ScreenPosition = ScreenPosition;
    params.Scale = Scale;
    params.RenderColor = RenderColor;
    params.Kerning = Kerning;
    params.ShadowColor = ShadowColor;
    params.ShadowOffset = ShadowOffset;
    params.bCentreX = bCentreX;
    params.bCentreY = bCenterY;
    params.bOutlined = bOutlined;
    params.OutlineColor = OutlineColor;
    ProcessEvent(functions::K2_DrawText_FN, &params);
}

void UCanvas::K2_DrawLine(FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor) {
    struct {
        FVector2D ScreenPositionA;
        FVector2D ScreenPositionB;
        float Thickness;
        FLinearColor RenderColor;
    }params{};

    params.ScreenPositionA = ScreenPositionA;
    params.ScreenPositionB = ScreenPositionB;
    params.Thickness = Thickness;
    params.RenderColor = RenderColor;
    ProcessEvent(functions::K2_DrawLine_FN, &params);
}

bool AController::LineOfSightTo(AActor* Other, FVector ViewPoint, bool bAlternateChecks) {
    struct {
        AActor* Other;
        FVector ViewPoint;
        bool bAlternateChecks;
        bool return_value;
    }params{};

    params.Other = Other;
    params.ViewPoint = ViewPoint;
    params.bAlternateChecks = bAlternateChecks;
    ProcessEvent(functions::LineOfSightTo_FN, &params);
    return params.return_value;
}

APawn* AController::K2_GetPawn() {
    struct {
        APawn* return_value;
    }params{};
    ProcessEvent(functions::K2_GetPawn_FN, &params);
    return params.return_value;
}

bool APlayerController::ProjectWorldLocationToScreen(FVector WorldLocation, FVector2D& ScreenLocation, bool bPlayerViewportRelative) {
    struct {
        FVector WorldLocation;
        FVector2D ScreenLocation;
        bool bPlayerViewportRelative;
        bool return_value;
    }params{};

    params.WorldLocation = WorldLocation;
    params.ScreenLocation = ScreenLocation;
    params.bPlayerViewportRelative = bPlayerViewportRelative;
    ProcessEvent(functions::ProjectWorldLocationToScreen_FN, &params);
    ScreenLocation = params.ScreenLocation;
    return params.return_value;
}

void AActor::GetActorBounds(bool bOnlyCollidingComponents, FVector& Origin, FVector& BoxExtent, bool bIncludeFromChildActors) {
    struct {
        bool bOnlyCollidingComponents;
        FVector Origin;
        FVector BoxExtent;
        bool bIncludeFromChildActors;
    }params{};

    params.bOnlyCollidingComponents = bOnlyCollidingComponents;
    params.Origin = Origin;
    params.BoxExtent = BoxExtent;
    params.bIncludeFromChildActors = bIncludeFromChildActors;
    ProcessEvent(functions::GetActorBounds_FN, &params);
    Origin = params.Origin;
    BoxExtent = params.BoxExtent;
}

struct FString ARBPlayer::GetGamePlayerName() {
    struct {
        struct FString return_value;
    }params{};
    ProcessEvent(functions::GetGamePlayerName_FN, &params);
    return params.return_value;
}

struct URBArmWreslingPanelComponent* ARBArmWreslingTable::GetLocallyWatchedPanel() {
    struct {
        struct URBArmWreslingPanelComponent* return_value;
    }params{};
    ProcessEvent(functions::GetLocallyWatchedPanel_FN, &params);
    return params.return_value;
}

bool URBArmWreslingPanelComponent::IsArmWreslingRoundInProgress() {
    struct {
        bool return_value;
    }params{};
    ProcessEvent(functions::IsArmWreslingRoundInProgress_FN, &params);
    return params.return_value;
}
        
float URBArmWreslingPanelComponent::GetCursorPosition() {
    struct {
        float return_value;
    }params{};
    ProcessEvent(functions::GetCursorPosition_FN, &params);
    return params.return_value;
}

//bool URBInteractiblePanelComponent::IsPanelActive() {
//    struct {
//        bool return_value;
//    }params{};
//    ProcessEvent(functions::IsPanelActive_FN, &params);
//    return params.return_value;
//}
