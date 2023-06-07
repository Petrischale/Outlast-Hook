#pragma once
#include "engine.h"
#include <cstdint>

// Class Engine.ActorComponent
// Size: 0xb8 (Inherited: 0x28)
struct UActorComponent : UObject {
	char pad_00[0x90];
};

// Class Engine.SceneComponent
// Size: 0x220 (Inherited: 0xb8)
struct USceneComponent : UActorComponent {
	char pad_B8[0x8]; // 0xb8(0x08)
	char PhysicsVolume[0x08]; // 0xc0(0x08)
	struct USceneComponent* AttachParent; // 0xc8(0x08)
	struct FName AttachSocketName; // 0xd0(0x08)
	struct TArray<struct USceneComponent*> AttachChildren; // 0xd8(0x10)
	struct TArray<struct USceneComponent*> ClientAttachedChildren; // 0xe8(0x10)
	char pad_F8[0x2c]; // 0xf8(0x2c)
	struct FVector RelativeLocation; // 0x124(0x0c)
	struct FRotator RelativeRotation; // 0x130(0x0c)
	struct FVector RelativeScale3D; // 0x13c(0x0c)
	struct FVector ComponentVelocity; // 0x148(0x0c)
	char bComponentToWorldUpdated : 1; // 0x154(0x01)
	char pad_154_1 : 1; // 0x154(0x01)
	char bAbsoluteLocation : 1; // 0x154(0x01)
	char bAbsoluteRotation : 1; // 0x154(0x01)
	char bAbsoluteScale : 1; // 0x154(0x01)
	char bVisible : 1; // 0x154(0x01)
	char bShouldBeAttached : 1; // 0x154(0x01)
	char bShouldSnapLocationWhenAttached : 1; // 0x154(0x01)
	char bShouldSnapRotationWhenAttached : 1; // 0x155(0x01)
	char bShouldUpdatePhysicsVolume : 1; // 0x155(0x01)
	char bHiddenInGame : 1; // 0x155(0x01)
	char bBoundsChangeTriggersStreamingDataRebuild : 1; // 0x155(0x01)
	char bUseAttachParentBound : 1; // 0x155(0x01)
	char bAllowPrecomputedVisibilityOnMovable : 1; // 0x155(0x01)
	char bStoreLightingScenarioProperties : 1; // 0x155(0x01)
	char pad_155_7 : 1; // 0x155(0x01)
	char pad_156[0x1]; // 0x156(0x01)
	char Mobility; // 0x157(0x01)
	char DetailMode; // 0x158(0x01)
	char PhysicsVolumeChangedDelegate; // 0x159(0x01)
	char pad_15A[0x2]; // 0x15a(0x02)
	int32_t VisibilityId; // 0x15c(0x04)
	char pad_160[0xc0]; // 0x160(0xc0)

	bool IsVisible(); // Function Engine.SceneComponent.IsVisible // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d7c334
};

struct AActor : UObject {
	bool bDebugFlag; // 0x28(0x01)
	char pad_29[0x7]; // 0x29(0x07)
	char PrimaryActorTick[0x30]; // 0x30(0x30)
	char bNetTemporary : 1; // 0x60(0x01)
	char bNetStartup : 1; // 0x60(0x01)
	char bOnlyRelevantToOwner : 1; // 0x60(0x01)
	char bIsNotRelevantWhenHidden : 1; // 0x60(0x01)
	char bAlwaysRelevant : 1; // 0x60(0x01)
	char bReplicateMovement : 1; // 0x60(0x01)
	char bReplicateAttachment : 1; // 0x60(0x01)
	char bHidden : 1; // 0x60(0x01)
	char bTearOff : 1; // 0x61(0x01)
	char bForceNetAddressable : 1; // 0x61(0x01)
	char bExchangedRoles : 1; // 0x61(0x01)
	char bNetLoadOnClient : 1; // 0x61(0x01)
	char bNetUseOwnerRelevancy : 1; // 0x61(0x01)
	char bRelevantForNetworkReplays : 1; // 0x61(0x01)
	char bShouldResetWithStage : 1; // 0x61(0x01)
	char bRelevantForLevelBounds : 1; // 0x61(0x01)
	char bReplayRewindable : 1; // 0x62(0x01)
	char bAllowTickBeforeBeginPlay : 1; // 0x62(0x01)
	char bAutoDestroyWhenFinished : 1; // 0x62(0x01)
	char bCanBeDamaged : 1; // 0x62(0x01)
	char bBlockInput : 1; // 0x62(0x01)
	char bCollideWhenPlacing : 1; // 0x62(0x01)
	char bFindCameraComponentWhenViewTarget : 1; // 0x62(0x01)
	char bGenerateOverlapEventsDuringLevelStreaming : 1; // 0x62(0x01)
	char bIgnoresOriginShifting : 1; // 0x63(0x01)
	char bUseCustomEnableAutoLODGenerationValue : 1; // 0x63(0x01)
	char bEnableAutoLODGeneration : 1; // 0x63(0x01)
	char bIsEditorOnlyActor : 1; // 0x63(0x01)
	char bActorSeamlessTraveled : 1; // 0x63(0x01)
	char bStoreLightingScenarioProperties : 1; // 0x63(0x01)
	char bReplicates : 1; // 0x63(0x01)
	char bAuthorityWhenNotReplicated : 1; // 0x63(0x01)
	char bCanBeInCluster : 1; // 0x64(0x01)
	char bAllowReceiveTickEventOnDedicatedServer : 1; // 0x64(0x01)
	char pad_64_2 : 6; // 0x64(0x01)
	char pad_65_0 : 1; // 0x65(0x01)
	char bActorEnableCollision : 1; // 0x65(0x01)
	char bActorIsBeingDestroyed : 1; // 0x65(0x01)
	char pad_65_3 : 5; // 0x65(0x01)
	char UpdateOverlapsMethodDuringLevelStreaming; // 0x66(0x01)
	char DefaultUpdateOverlapsMethodDuringLevelStreaming; // 0x67(0x01)
	char RemoteRole; // 0x68(0x01)
	char pad_69[0x3]; // 0x69(0x03)
	char ReplicatedMovement[0x34]; // 0x6c(0x34)
	float InitialLifeSpan; // 0xa0(0x04)
	float CustomTimeDilation; // 0xa4(0x04)
	char pad_A8[0x8]; // 0xa8(0x08)
	char AttachmentReplication[0x40]; // 0xb0(0x40)
	struct AActor* Owner; // 0xf0(0x08)
	struct FName NetDriverName; // 0xf8(0x08)
	char Role; // 0x100(0x01)
	char NetDormancy; // 0x101(0x01)
	char SpawnCollisionHandlingMethod; // 0x102(0x01)
	char AutoReceiveInput; // 0x103(0x01)
	int InputPriority; // 0x104(0x04)
	struct UInputComponent* InputComponent; // 0x108(0x08)
	float NetCullDistanceSquared; // 0x110(0x04)
	int NetTag; // 0x114(0x04)
	float NetUpdateFrequency; // 0x118(0x04)
	float MinNetUpdateFrequency; // 0x11c(0x04)
	float NetPriority; // 0x120(0x04)
	char pad_124[0x4]; // 0x124(0x04)
	struct APawn* Instigator; // 0x128(0x08)
	struct TArray<struct AActor*> Children; // 0x130(0x10)
	struct USceneComponent* RootComponent; // 0x140(0x08)
	struct TArray<struct AMatineeActor*> ControllingMatineeActors; // 0x148(0x10)
	char pad_158[0x8]; // 0x158(0x08)
	struct TArray<struct FName> Layers; // 0x160(0x10)
	char bOverride_ForceNoVolumetricLightMap : 1; // 0x170(0x01)
	char bForceNoVolumetricLightMap : 1; // 0x170(0x01)
	char pad_170_2 : 6; // 0x170(0x01)
	char pad_171[0x3]; // 0x171(0x03)
	char ParentComponent[0x08]; // 0x174(0x08)
	char pad_17C[0x1c]; // 0x17c(0x1c)
	struct TArray<struct FName> Tags; // 0x198(0x10)
	char OnTakeAnyDamage; // 0x1a8(0x01)
	char OnTakePointDamage; // 0x1a9(0x01)
	char OnTakeRadialDamage; // 0x1aa(0x01)
	char OnActorBeginOverlap; // 0x1ab(0x01)
	char OnActorEndOverlap; // 0x1ac(0x01)
	char OnBeginCursorOver; // 0x1ad(0x01)
	char OnEndCursorOver; // 0x1ae(0x01)
	char OnClicked; // 0x1af(0x01)
	char OnReleased; // 0x1b0(0x01)
	char OnInputTouchBegin; // 0x1b1(0x01)
	char OnInputTouchEnd; // 0x1b2(0x01)
	char OnInputTouchEnter; // 0x1b3(0x01)
	char OnInputTouchLeave; // 0x1b4(0x01)
	char OnActorHit; // 0x1b5(0x01)
	char OnDestroyed; // 0x1b6(0x01)
	char OnEndPlay; // 0x1b7(0x01)
	char pad_1B8[0x60]; // 0x1b8(0x60)
	struct TArray<struct UActorComponent*> InstanceComponents; // 0x218(0x10)
	struct TArray<struct UActorComponent*> BlueprintCreatedComponents; // 0x228(0x10)
	char pad_238[0x10]; // 0x238(0x10)
	bool WasRecentlyRendered(float Tolerance); // Function Engine.Actor.WasRecentlyRendered // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34948e4
	void UserConstructionScript(); // Function Engine.Actor.UserConstructionScript // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void TearOff(); // Function Engine.Actor.TearOff // (Native|Public|BlueprintCallable) // @ game+0x2672598
	void SnapRootComponentTo(struct AActor* InParentActor, struct FName InSocketName); // Function Engine.Actor.SnapRootComponentTo // (Final|Native|Public|BlueprintCallable) // @ game+0x34947f4
	void SetTickGroup(enum class ETickingGroup NewTickGroup); // Function Engine.Actor.SetTickGroup // (Final|Native|Public|BlueprintCallable) // @ game+0x34946f8
	void SetTickableWhenPaused(bool bTickableWhenPaused); // Function Engine.Actor.SetTickableWhenPaused // (Final|Native|Public|BlueprintCallable) // @ game+0x3494774
	void SetReplicates(bool bInReplicates); // Function Engine.Actor.SetReplicates // (Final|BlueprintAuthorityOnly|Native|Public|BlueprintCallable) // @ game+0x3494678
	void SetReplicateMovement(bool bInReplicateMovement); // Function Engine.Actor.SetReplicateMovement // (Native|Public|BlueprintCallable) // @ game+0x34945f4
	void SetOwner(struct AActor* NewOwner); // Function Engine.Actor.SetOwner // (Native|Public|BlueprintCallable) // @ game+0x3494570
	void SetOverrideForceNoVolumetricLightMap(bool bOverrideNoVolumetricLightMap); // Function Engine.Actor.SetOverrideForceNoVolumetricLightMap // (Final|Native|Public|BlueprintCallable) // @ game+0x34944f0
	void SetNetDormancy(enum class ENetDormancy NewDormancy); // Function Engine.Actor.SetNetDormancy // (Final|BlueprintAuthorityOnly|Native|Public|BlueprintCallable) // @ game+0x3494470
	void SetLifeSpan(float InLifespan); // Function Engine.Actor.SetLifeSpan // (Native|Public|BlueprintCallable) // @ game+0x34943e8
	void SetForceNoVolumetricLightMap(bool bNoVolumetricLightMap); // Function Engine.Actor.SetForceNoVolumetricLightMap // (Final|Native|Public|BlueprintCallable) // @ game+0x349433c
	void SetAutoDestroyWhenFinished(bool bVal); // Function Engine.Actor.SetAutoDestroyWhenFinished // (Final|Native|Public|BlueprintCallable) // @ game+0x3494278
	void SetActorTickInterval(float TickInterval); // Function Engine.Actor.SetActorTickInterval // (Final|Native|Public|BlueprintCallable) // @ game+0x34941f4
	void SetActorTickEnabled(bool bEnabled); // Function Engine.Actor.SetActorTickEnabled // (Final|Native|Public|BlueprintCallable) // @ game+0x3494174
	void SetActorScale3D(struct FVector NewScale3D); // Function Engine.Actor.SetActorScale3D // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34940e4
	void SetActorRelativeScale3D(struct FVector NewRelativeScale); // Function Engine.Actor.SetActorRelativeScale3D // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x3494054
	void SetActorHiddenInGame(bool bNewHidden); // Function Engine.Actor.SetActorHiddenInGame // (Native|Public|BlueprintCallable) // @ game+0x3493fd0
	void SetActorEnableCollision(bool bNewActorEnableCollision); // Function Engine.Actor.SetActorEnableCollision // (Final|Native|Public|BlueprintCallable) // @ game+0x3493f50
	void RemoveTickPrerequisiteComponent(struct UActorComponent* PrerequisiteComponent); // Function Engine.Actor.RemoveTickPrerequisiteComponent // (Native|Public|BlueprintCallable) // @ game+0x3493ecc
	void RemoveTickPrerequisiteActor(struct AActor* PrerequisiteActor); // Function Engine.Actor.RemoveTickPrerequisiteActor // (Native|Public|BlueprintCallable) // @ game+0x3493e48
	void ReceiveTick(float DeltaSeconds); // Function Engine.Actor.ReceiveTick // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveRadialDamage(float DamageReceived, struct UDamageType* DamageType, struct FVector Origin, struct FHitResult& HitInfo, struct AController* InstigatedBy, struct AActor* DamageCauser); // Function Engine.Actor.ReceiveRadialDamage // (BlueprintAuthorityOnly|Event|Public|HasOutParms|HasDefaults|BlueprintEvent) // @ game+0x201e6d4
	void ReceivePointDamage(float Damage, struct UDamageType* DamageType, struct FVector HitLocation, struct FVector HitNormal, struct UPrimitiveComponent* HitComponent, struct FName BoneName, struct FVector ShotFromDirection, struct AController* InstigatedBy, struct AActor* DamageCauser, struct FHitResult& HitInfo); // Function Engine.Actor.ReceivePointDamage // (BlueprintAuthorityOnly|Event|Public|HasOutParms|HasDefaults|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveHit(struct UPrimitiveComponent* MyComp, struct AActor* Other, struct UPrimitiveComponent* OtherComp, bool bSelfMoved, struct FVector HitLocation, struct FVector HitNormal, struct FVector NormalImpulse, struct FHitResult& Hit); // Function Engine.Actor.ReceiveHit // (Event|Public|HasOutParms|HasDefaults|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveEndPlay(enum class EEndPlayReason EndPlayReason); // Function Engine.Actor.ReceiveEndPlay // (Event|Protected|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveDestroyed(); // Function Engine.Actor.ReceiveDestroyed // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveBeginPlay(); // Function Engine.Actor.ReceiveBeginPlay // (Event|Protected|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveAnyDamage(float Damage, struct UDamageType* DamageType, struct AController* InstigatedBy, struct AActor* DamageCauser); // Function Engine.Actor.ReceiveAnyDamage // (BlueprintAuthorityOnly|Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnReleased(struct FKey ButtonReleased); // Function Engine.Actor.ReceiveActorOnReleased // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnInputTouchLeave(enum class ETouchIndex FingerIndex); // Function Engine.Actor.ReceiveActorOnInputTouchLeave // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnInputTouchEnter(enum class ETouchIndex FingerIndex); // Function Engine.Actor.ReceiveActorOnInputTouchEnter // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnInputTouchEnd(enum class ETouchIndex FingerIndex); // Function Engine.Actor.ReceiveActorOnInputTouchEnd // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnInputTouchBegin(enum class ETouchIndex FingerIndex); // Function Engine.Actor.ReceiveActorOnInputTouchBegin // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorOnClicked(struct FKey ButtonPressed); // Function Engine.Actor.ReceiveActorOnClicked // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorEndOverlap(struct AActor* OtherActor); // Function Engine.Actor.ReceiveActorEndOverlap // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorEndCursorOver(); // Function Engine.Actor.ReceiveActorEndCursorOver // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorBeginOverlap(struct AActor* OtherActor); // Function Engine.Actor.ReceiveActorBeginOverlap // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveActorBeginCursorOver(); // Function Engine.Actor.ReceiveActorBeginCursorOver // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void PrestreamTextures(float Seconds, bool bEnableStreaming, int32_t CinematicTextureGroups); // Function Engine.Actor.PrestreamTextures // (Native|Public|BlueprintCallable) // @ game+0x3493d44
	void OnRep_ReplicateMovement(); // Function Engine.Actor.OnRep_ReplicateMovement // (Native|Public) // @ game+0x2672580
	void OnRep_ReplicatedMovement(); // Function Engine.Actor.OnRep_ReplicatedMovement // (Native|Public) // @ game+0x3493d2c
	void OnRep_Owner(); // Function Engine.Actor.OnRep_Owner // (Native|Protected) // @ game+0x2d70684
	void OnRep_Instigator(); // Function Engine.Actor.OnRep_Instigator // (Native|Public) // @ game+0x3493d14
	void OnRep_AttachmentReplication(); // Function Engine.Actor.OnRep_AttachmentReplication // (Native|Public) // @ game+0x2672278
	void MakeNoise(float Loudness, struct APawn* NoiseInstigator, struct FVector NoiseLocation, float MaxRange, struct FName Tag); // Function Engine.Actor.MakeNoise // (Final|BlueprintAuthorityOnly|Native|Public|HasDefaults) // @ game+0x3493b80
	struct UMaterialInstanceDynamic* MakeMIDForMaterial(struct UMaterialInterface* Parent); // Function Engine.Actor.MakeMIDForMaterial // (Final|Native|Public|BlueprintCallable) // @ game+0x2e99960
	bool K2_TeleportTo(struct FVector DestLocation, struct FRotator DestRotation); // Function Engine.Actor.K2_TeleportTo // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x3493a8c
	bool K2_SetActorTransform(struct FTransform& NewTransform, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorTransform // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34938b4
	bool K2_SetActorRotation(struct FRotator NewRotation, bool bTeleportPhysics); // Function Engine.Actor.K2_SetActorRotation // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34937d0
	void K2_SetActorRelativeTransform(struct FTransform& NewRelativeTransform, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorRelativeTransform // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34935fc
	void K2_SetActorRelativeRotation(struct FRotator NewRelativeRotation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorRelativeRotation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3493480
	void K2_SetActorRelativeLocation(struct FVector NewRelativeLocation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorRelativeLocation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3493304
	bool K2_SetActorLocationAndRotation(struct FVector NewLocation, struct FRotator NewRotation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorLocationAndRotation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3493120
	bool K2_SetActorLocation(struct FVector NewLocation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_SetActorLocation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3492f94
	void K2_OnReset(); // Function Engine.Actor.K2_OnReset // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void K2_OnEndViewTarget(struct APlayerController* PC); // Function Engine.Actor.K2_OnEndViewTarget // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void K2_OnBecomeViewTarget(struct APlayerController* PC); // Function Engine.Actor.K2_OnBecomeViewTarget // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	struct USceneComponent* K2_GetRootComponent(); // Function Engine.Actor.K2_GetRootComponent // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3492f7c
	struct TArray<struct UActorComponent*> K2_GetComponentsByClass(struct UActorComponent* ComponentClass); // Function Engine.Actor.K2_GetComponentsByClass // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3492ea4
	struct FRotator K2_GetActorRotation(); // Function Engine.Actor.K2_GetActorRotation // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3492dec
	struct FVector K2_GetActorLocation(); // Function Engine.Actor.K2_GetActorLocation // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3492d78
	void K2_DetachFromActor(enum class EDetachmentRule LocationRule, enum class EDetachmentRule RotationRule, enum class EDetachmentRule ScaleRule); // Function Engine.Actor.K2_DetachFromActor // (Final|Native|Public|BlueprintCallable) // @ game+0x3492c70
	void K2_DestroyComponent(struct UActorComponent* Component); // Function Engine.Actor.K2_DestroyComponent // (Final|Native|Public|BlueprintCallable) // @ game+0x3492be8
	void K2_DestroyActor(); // Function Engine.Actor.K2_DestroyActor // (Native|Public|BlueprintCallable) // @ game+0x3492bd0
	void K2_AttachToComponent(struct USceneComponent* Parent, struct FName SocketName, enum class EAttachmentRule LocationRule, enum class EAttachmentRule RotationRule, enum class EAttachmentRule ScaleRule, bool bWeldSimulatedBodies); // Function Engine.Actor.K2_AttachToComponent // (Final|Native|Public|BlueprintCallable) // @ game+0x34929f8
	void K2_AttachToActor(struct AActor* ParentActor, struct FName SocketName, enum class EAttachmentRule LocationRule, enum class EAttachmentRule RotationRule, enum class EAttachmentRule ScaleRule, bool bWeldSimulatedBodies); // Function Engine.Actor.K2_AttachToActor // (Final|Native|Public|BlueprintCallable) // @ game+0x3492808
	void K2_AddActorWorldTransformKeepScale(struct FTransform& DeltaTransform, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorWorldTransformKeepScale // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3492640
	void K2_AddActorWorldTransform(struct FTransform& DeltaTransform, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorWorldTransform // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3492478
	void K2_AddActorWorldRotation(struct FRotator DeltaRotation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorWorldRotation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34922fc
	void K2_AddActorWorldOffset(struct FVector DeltaLocation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorWorldOffset // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3492180
	void K2_AddActorLocalTransform(struct FTransform& NewTransform, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorLocalTransform // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3491fb8
	void K2_AddActorLocalRotation(struct FRotator DeltaRotation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorLocalRotation // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3491e3c
	void K2_AddActorLocalOffset(struct FVector DeltaLocation, bool bSweep, struct FHitResult& SweepHitResult, bool bTeleport); // Function Engine.Actor.K2_AddActorLocalOffset // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x3491cc0
	bool IsOverlappingActor(struct AActor* Other); // Function Engine.Actor.IsOverlappingActor // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491c30
	bool IsChildActor(); // Function Engine.Actor.IsChildActor // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491c08
	bool IsActorTickEnabled(); // Function Engine.Actor.IsActorTickEnabled // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491bf0
	bool IsActorBeingDestroyed(); // Function Engine.Actor.IsActorBeingDestroyed // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491bd4
	bool HasAuthority(); // Function Engine.Actor.HasAuthority // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491ba8
	float GetVerticalDistanceTo(struct AActor* OtherActor); // Function Engine.Actor.GetVerticalDistanceTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491a70
	struct FVector GetVelocity(); // Function Engine.Actor.GetVelocity // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491a38
	struct FTransform GetTransform(); // Function Engine.Actor.GetTransform // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491a04
	bool GetTickableWhenPaused(); // Function Engine.Actor.GetTickableWhenPaused // (Final|Native|Public|BlueprintCallable) // @ game+0x34919ec
	float GetSquaredHorizontalDistanceTo(struct AActor* OtherActor); // Function Engine.Actor.GetSquaredHorizontalDistanceTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x349189c
	float GetSquaredDistanceTo(struct AActor* OtherActor); // Function Engine.Actor.GetSquaredDistanceTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x349172c
	enum class ENetRole GetRemoteRole(); // Function Engine.Actor.GetRemoteRole // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491718
	struct UChildActorComponent* GetParentComponent(); // Function Engine.Actor.GetParentComponent // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34916f0
	struct AActor* GetParentActor(); // Function Engine.Actor.GetParentActor // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34916cc
	struct AActor* GetOwner(); // Function Engine.Actor.GetOwner // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34916b4
	void GetOverlappingComponents(struct TArray<struct UPrimitiveComponent*>& OverlappingComponents); // Function Engine.Actor.GetOverlappingComponents // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x349161c
	void GetOverlappingActors(struct TArray<struct AActor*>& OverlappingActors, struct AActor* ClassFilter); // Function Engine.Actor.GetOverlappingActors // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491530
	enum class ENetRole GetLocalRole(); // Function Engine.Actor.GetLocalRole // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491518
	float GetLifeSpan(); // Function Engine.Actor.GetLifeSpan // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34914ec
	struct AController* GetInstigatorController(); // Function Engine.Actor.GetInstigatorController // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34914cc
	struct APawn* GetInstigator(); // Function Engine.Actor.GetInstigator // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x2696410
	struct FVector GetInputVectorAxisValue(struct FKey InputAxisKey); // Function Engine.Actor.GetInputVectorAxisValue // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3491388
	float GetInputAxisValue(struct FName InputAxisName); // Function Engine.Actor.GetInputAxisValue // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34912f8
	float GetInputAxisKeyValue(struct FKey InputAxisKey); // Function Engine.Actor.GetInputAxisKeyValue // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x349121c
	float GetHorizontalDotProductTo(struct AActor* OtherActor); // Function Engine.Actor.GetHorizontalDotProductTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490f8c
	float GetHorizontalDistanceTo(struct AActor* OtherActor); // Function Engine.Actor.GetHorizontalDistanceTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490e34
	float GetGameTimeSinceCreation(); // Function Engine.Actor.GetGameTimeSinceCreation // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490e0c
	float GetDotProductTo(struct AActor* OtherActor); // Function Engine.Actor.GetDotProductTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490b64
	float GetDistanceTo(struct AActor* OtherActor); // Function Engine.Actor.GetDistanceTo // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34909ec
	struct TArray<struct UActorComponent*> GetComponentsByTag(struct UActorComponent* ComponentClass, struct FName Tag); // Function Engine.Actor.GetComponentsByTag // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490910
	struct TArray<struct UActorComponent*> GetComponentsByInterface(struct UInterface* Interface); // Function Engine.Actor.GetComponentsByInterface // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x349072c
	struct UActorComponent* GetComponentByClass(struct UActorComponent* ComponentClass); // Function Engine.Actor.GetComponentByClass // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490698
	struct FName GetAttachParentSocketName(); // Function Engine.Actor.GetAttachParentSocketName // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490584
	struct AActor* GetAttachParentActor(); // Function Engine.Actor.GetAttachParentActor // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490564
	void GetAttachedActors(struct TArray<struct AActor*>& OutActors, bool bResetArray); // Function Engine.Actor.GetAttachedActors // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x34905ac
	void GetAllChildActors(struct TArray<struct AActor*>& ChildActors, bool bIncludeDescendants); // Function Engine.Actor.GetAllChildActors // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490478
	struct FVector GetActorUpVector(); // Function Engine.Actor.GetActorUpVector // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490418
	float GetActorTimeDilation(); // Function Engine.Actor.GetActorTimeDilation // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34903f0
	float GetActorTickInterval(); // Function Engine.Actor.GetActorTickInterval // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34903dc
	struct FVector GetActorScale3D(); // Function Engine.Actor.GetActorScale3D // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34903ac
	struct FVector GetActorRightVector(); // Function Engine.Actor.GetActorRightVector // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x349034c
	struct FVector GetActorRelativeScale3D(); // Function Engine.Actor.GetActorRelativeScale3D // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34902f0
	struct FVector GetActorForwardVector(); // Function Engine.Actor.GetActorForwardVector // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490290
	void GetActorEyesViewPoint(struct FVector& OutLocation, struct FRotator& OutRotation); // Function Engine.Actor.GetActorEyesViewPoint // (Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34901b4
	bool GetActorEnableCollision(); // Function Engine.Actor.GetActorEnableCollision // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x349019c
	void GetActorBounds(bool bOnlyCollidingComponents, struct FVector& Origin, struct FVector& BoxExtent, bool bIncludeFromChildActors); // Function Engine.Actor.GetActorBounds // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x3490034
	void ForceNetUpdate(); // Function Engine.Actor.ForceNetUpdate // (Native|Public|BlueprintCallable) // @ game+0x349001c
	void FlushNetDormancy(); // Function Engine.Actor.FlushNetDormancy // (Final|BlueprintAuthorityOnly|Native|Public|BlueprintCallable) // @ game+0x3490008
	void FinishAddComponent(struct UActorComponent* Component, bool bManualAttachment, struct FTransform& RelativeTransform); // Function Engine.Actor.FinishAddComponent // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x348fd6c
	void Event_PostRegisterAllComponents(); // Function Engine.Actor.Event_PostRegisterAllComponents // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void Event_PostInitializeComponents(); // Function Engine.Actor.Event_PostInitializeComponents // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void Event_OnResetStage(); // Function Engine.Actor.Event_OnResetStage // (Event|Public|BlueprintEvent) // @ game+0x201e6d4
	void EnableInput(struct APlayerController* PlayerController); // Function Engine.Actor.EnableInput // (Native|Public|BlueprintCallable) // @ game+0x348fce8
	void DisableInput(struct APlayerController* PlayerController); // Function Engine.Actor.DisableInput // (Native|Public|BlueprintCallable) // @ game+0x16b2afc
	void DetachRootComponentFromParent(bool bMaintainWorldPosition); // Function Engine.Actor.DetachRootComponentFromParent // (Final|Native|Public|BlueprintCallable) // @ game+0x348fc04
	void AddTickPrerequisiteComponent(struct UActorComponent* PrerequisiteComponent); // Function Engine.Actor.AddTickPrerequisiteComponent // (Native|Public|BlueprintCallable) // @ game+0x348fb80
	void AddTickPrerequisiteActor(struct AActor* PrerequisiteActor); // Function Engine.Actor.AddTickPrerequisiteActor // (Native|Public|BlueprintCallable) // @ game+0x348fafc
	struct UActorComponent* AddComponentByClass(struct UActorComponent* Class, bool bManualAttachment, struct FTransform& RelativeTransform, bool bDeferredFinish); // Function Engine.Actor.AddComponentByClass // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x348f8a8
	struct UActorComponent* AddComponent(struct FName TemplateName, bool bManualAttachment, struct FTransform& RelativeTransform, struct UObject* ComponentTemplateContext, bool bDeferredFinish); // Function Engine.Actor.AddComponent // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x348f6c0
	bool ActorHasTag(struct FName Tag); // Function Engine.Actor.ActorHasTag // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x348f630
};

struct APlayerState : AActor {
	int32_t PlayerId; // 0x248(0x04)
	char Ping; // 0x24c(0x01)
	char pad_24D[0x1]; // 0x24d(0x01)
	char bShouldUpdateReplicatedPing : 1; // 0x24e(0x01)
	char bIsSpectator : 1; // 0x24e(0x01)
	char bOnlySpectator : 1; // 0x24e(0x01)
	char bIsABot : 1; // 0x24e(0x01)
	char pad_24E_4 : 1; // 0x24e(0x01)
	char bIsInactive : 1; // 0x24e(0x01)
	char bFromPreviousLevel : 1; // 0x24e(0x01)
	char pad_24E_7 : 1; // 0x24e(0x01)
	char pad_24F[0x1]; // 0x24f(0x01)
	int32_t StartTime; // 0x250(0x04)
	char pad_254[0x4]; // 0x254(0x04)
	struct ULocalMessage* EngineMessageClass; // 0x258(0x08)
	char pad_260[0x8]; // 0x260(0x08)
	char SavedNetworkAddress[0x10]; // 0x268(0x10)
	char UniqueId[0x28]; // 0x278(0x28)
	char pad_2A0[0x8]; // 0x2a0(0x08)
	struct APawn* PawnPrivate; // 0x2a8(0x08)
	char pad_2B0[0x78]; // 0x2b0(0x78)
	char PlayerNamePrivate[0x10]; // 0x328(0x10)
	char pad_338[0x10]; // 0x338(0x10)
};

struct AController : AActor {
	char pad_248[0x8]; // 0x248(0x08)
	struct APlayerState* PlayerState; // 0x250(0x08)
	char pad_258[0x8]; // 0x258(0x08)
	char OnInstigatedAnyDamage[0x10]; // 0x260(0x10)
	struct FName StateName; // 0x270(0x08)
	struct APawn* Pawn; // 0x278(0x08)
	char pad_280[0x8]; // 0x280(0x08)
	struct ACharacter* Character; // 0x288(0x08)
	struct USceneComponent* TransformComponent; // 0x290(0x08)
	char pad_298[0x18]; // 0x298(0x18)
	struct FRotator ControlRotation; // 0x2b0(0x0c)
	char bAttachToPawn : 1; // 0x2bc(0x01)
	char pad_2BC_1 : 7; // 0x2bc(0x01)
	char pad_2BD[0x3]; // 0x2bd(0x03)


	void UnPossess(); // Function Engine.Controller.UnPossess // (Final|Native|Public|BlueprintCallable) // @ game+0x34d0900
	void StopMovement(); // Function Engine.Controller.StopMovement // (Native|Public|BlueprintCallable) // @ game+0x34d08e8
	void SetInitialLocationAndRotation(struct FVector& NewLocation, struct FRotator& NewRotation); // Function Engine.Controller.SetInitialLocationAndRotation // (Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34d080c
	void SetIgnoreMoveInput(bool bNewMoveInput); // Function Engine.Controller.SetIgnoreMoveInput // (Native|Public|BlueprintCallable) // @ game+0x34d0788
	void SetIgnoreLookInput(bool bNewLookInput); // Function Engine.Controller.SetIgnoreLookInput // (Native|Public|BlueprintCallable) // @ game+0x34d0704
	void SetControlRotation(struct FRotator& NewRotation); // Function Engine.Controller.SetControlRotation // (Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34d067c
	void ResetIgnoreMoveInput(); // Function Engine.Controller.ResetIgnoreMoveInput // (Native|Public|BlueprintCallable) // @ game+0x34d0664
	void ResetIgnoreLookInput(); // Function Engine.Controller.ResetIgnoreLookInput // (Native|Public|BlueprintCallable) // @ game+0x34d064c
	void ResetIgnoreInputFlags(); // Function Engine.Controller.ResetIgnoreInputFlags // (Native|Public|BlueprintCallable) // @ game+0x34d0634
	void ReceiveUnPossess(struct APawn* UnpossessedPawn); // Function Engine.Controller.ReceiveUnPossess // (Event|Protected|BlueprintEvent) // @ game+0x201e6d4
	void ReceivePossess(struct APawn* PossessedPawn); // Function Engine.Controller.ReceivePossess // (Event|Protected|BlueprintEvent) // @ game+0x201e6d4
	void ReceiveInstigatedAnyDamage(float Damage, struct UDamageType* DamageType, struct AActor* DamagedActor, struct AActor* DamageCauser); // Function Engine.Controller.ReceiveInstigatedAnyDamage // (BlueprintAuthorityOnly|Event|Protected|BlueprintEvent) // @ game+0x201e6d4
	void Possess(struct APawn* InPawn); // Function Engine.Controller.Possess // (Final|BlueprintAuthorityOnly|Native|Public|BlueprintCallable) // @ game+0x34d05b4
	void OnRep_PlayerState(); // Function Engine.Controller.OnRep_PlayerState // (Native|Public) // @ game+0x34d059c
	void OnRep_Pawn(); // Function Engine.Controller.OnRep_Pawn // (Native|Public) // @ game+0x34d0584
	bool LineOfSightTo(struct AActor* Other, struct FVector ViewPoint, bool bAlternateChecks); // Function Engine.Controller.LineOfSightTo // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d0468
	struct APawn* K2_GetPawn(); // Function Engine.Controller.K2_GetPawn // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d995cc
	bool IsPlayerController(); // Function Engine.Controller.IsPlayerController // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d044c
	bool IsMoveInputIgnored(); // Function Engine.Controller.IsMoveInputIgnored // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d0424
	bool IsLookInputIgnored(); // Function Engine.Controller.IsLookInputIgnored // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d03fc
	bool IsLocalPlayerController(); // Function Engine.Controller.IsLocalPlayerController // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d03b8
	bool IsLocalController(); // Function Engine.Controller.IsLocalController // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d0390
	struct AActor* GetViewTarget(); // Function Engine.Controller.GetViewTarget // (Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d0368
	struct FRotator GetDesiredRotation(); // Function Engine.Controller.GetDesiredRotation // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d0330
	struct FRotator GetControlRotation(); // Function Engine.Controller.GetControlRotation // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x34d02f8
	void ClientSetRotation(struct FRotator NewRotation, bool bResetCamera); // Function Engine.Controller.ClientSetRotation // (Net|NetReliableNative|Event|Public|HasDefaults|NetClient|NetValidate) // @ game+0x34d01e0
	void ClientSetLocation(struct FVector NewLocation, struct FRotator NewRotation); // Function Engine.Controller.ClientSetLocation // (Net|NetReliableNative|Event|Public|HasDefaults|NetClient|NetValidate) // @ game+0x34d00bc
	struct APlayerController* CastToPlayerController(); // Function Engine.Controller.CastToPlayerController // (Final|Native|Public|BlueprintCallable) // @ game+0x34d0080
};

struct APlayerController : AController {
	struct UPlayer* Player; // 0x2c0(0x08)
	struct APawn* AcknowledgedPawn; // 0x2c8(0x08)
	struct UInterpTrackInstDirector* ControllingDirTrackInst; // 0x2d0(0x08)
	struct AHUD* MyHUD; // 0x2d8(0x08)
	struct APlayerCameraManager* PlayerCameraManager; // 0x2e0(0x08)
	struct APlayerCameraManager* PlayerCameraManagerClass; // 0x2e8(0x08)
	bool bAutoManageActiveCameraTarget; // 0x2f0(0x01)
	char pad_2F1[0x3]; // 0x2f1(0x03)
	struct FRotator TargetViewRotation; // 0x2f4(0x0c)
	char pad_300[0xc]; // 0x300(0x0c)
	float SmoothTargetViewRotationSpeed; // 0x30c(0x04)
	char pad_310[0x8]; // 0x310(0x08)
	struct TArray<struct AActor*> HiddenActors; // 0x318(0x10)
	struct TArray<UObject> HiddenPrimitiveComponents; // 0x328(0x10)
	char pad_338[0x4]; // 0x338(0x04)
	float LastSpectatorStateSynchTime; // 0x33c(0x04)
	struct FVector LastSpectatorSyncLocation; // 0x340(0x0c)
	struct FRotator LastSpectatorSyncRotation; // 0x34c(0x0c)
	int32_t ClientCap; // 0x358(0x04)
	char pad_35C[0x4]; // 0x35c(0x04)
	struct UCheatManager* CheatManager; // 0x360(0x08)
	struct UCheatManager* CheatClass; // 0x368(0x08)
	struct UPlayerInput* PlayerInput; // 0x370(0x08)
	struct TArray<struct FActiveForceFeedbackEffect> ActiveForceFeedbackEffects; // 0x378(0x10)
	char pad_388[0x70]; // 0x388(0x70)
	char pad_3F8_0 : 4; // 0x3f8(0x01)
	char bPlayerIsWaiting : 1; // 0x3f8(0x01)
	char pad_3F8_5 : 3; // 0x3f8(0x01)
	char pad_3F9[0x3]; // 0x3f9(0x03)
	char NetPlayerIndex; // 0x3fc(0x01)
	char pad_3FD[0x3b]; // 0x3fd(0x3b)
	struct UNetConnection* PendingSwapConnection; // 0x438(0x08)
	struct UNetConnection* NetConnection; // 0x440(0x08)
	char pad_448[0xc]; // 0x448(0x0c)
	float InputYawScale; // 0x454(0x04)
	float InputPitchScale; // 0x458(0x04)
	float InputRollScale; // 0x45c(0x04)
	char bShowMouseCursor : 1; // 0x460(0x01)
	char bEnableClickEvents : 1; // 0x460(0x01)
	char bEnableTouchEvents : 1; // 0x460(0x01)
	char bEnableMouseOverEvents : 1; // 0x460(0x01)
	char bEnableTouchOverEvents : 1; // 0x460(0x01)
	char bForceFeedbackEnabled : 1; // 0x460(0x01)
	char pad_460_6 : 2; // 0x460(0x01)
	char pad_461[0x3]; // 0x461(0x03)
	float ForceFeedbackScale; // 0x464(0x04)
	struct TArray<struct FKey> ClickEventKeys; // 0x468(0x10)
	char DefaultMouseCursor; // 0x478(0x01)
	char CurrentMouseCursor; // 0x479(0x01)
	char DefaultClickTraceChannel; // 0x47a(0x01)
	char CurrentClickTraceChannel; // 0x47b(0x01)
	float HitResultTraceDistance; // 0x47c(0x04)
	uint16_t SeamlessTravelCount; // 0x480(0x02)
	uint16_t LastCompletedSeamlessTravelCount; // 0x482(0x02)
	char pad_484[0x74]; // 0x484(0x74)
	struct UInputComponent* InactiveStateInputComponent; // 0x4f8(0x08)
	char pad_500_0 : 2; // 0x500(0x01)
	char bShouldPerformFullTickWhenPaused : 1; // 0x500(0x01)
	char pad_500_3 : 5; // 0x500(0x01)
	char pad_501[0x17]; // 0x501(0x17)
	struct UTouchInterface* CurrentTouchInterface; // 0x518(0x08)
	char pad_520[0x50]; // 0x520(0x50)
	struct ASpectatorPawn* SpectatorPawn; // 0x570(0x08)
	char pad_578[0x4]; // 0x578(0x04)
	bool bIsLocalPlayerController; // 0x57c(0x01)
	char pad_57D[0x3]; // 0x57d(0x03)
	struct FVector SpawnLocation; // 0x580(0x0c)
	char pad_58C[0xc]; // 0x58c(0x0c)

	bool WasInputKeyJustReleased(struct FKey Key); // Function Engine.PlayerController.WasInputKeyJustReleased // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35ac408
	bool WasInputKeyJustPressed(struct FKey Key); // Function Engine.PlayerController.WasInputKeyJustPressed // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35ac2e0
	void ToggleSpeaking(bool bInSpeaking); // Function Engine.PlayerController.ToggleSpeaking // (Exec|Native|Public) // @ game+0x35ac25c
	void TestServerLevelVisibilityChange(struct FName PackageName, struct FName Filename); // Function Engine.PlayerController.TestServerLevelVisibilityChange // (Final|Exec|Native|Private) // @ game+0x35ac1b8
	void SwitchLevel(struct FString URL); // Function Engine.PlayerController.SwitchLevel // (Exec|Native|Public) // @ game+0x35ac124
	void StopHapticEffect(enum class EControllerHand hand); // Function Engine.PlayerController.StopHapticEffect // (Final|Native|Public|BlueprintCallable) // @ game+0x35ac090
	void StartFire(char FireModeNum); // Function Engine.PlayerController.StartFire // (Exec|Native|Public) // @ game+0x35ab9f0
	void SetVirtualJoystickVisibility(bool bVisible); // Function Engine.PlayerController.SetVirtualJoystickVisibility // (Native|Public|BlueprintCallable) // @ game+0x35ab4a8
	void SetViewTargetWithBlend(struct AActor* NewViewTarget, float blendTime, enum class EViewTargetBlendFunction BlendFunc, float BlendExp, bool bLockOutgoing); // Function Engine.PlayerController.SetViewTargetWithBlend // (Native|Public|BlueprintCallable) // @ game+0x35ab320
	void SetName(struct FString S); // Function Engine.PlayerController.SetName // (Exec|Native|Public) // @ game+0x35ab28c
	void SetMouseLocation(int32_t X, int32_t Y); // Function Engine.PlayerController.SetMouseLocation // (Final|Native|Public|BlueprintCallable) // @ game+0x35ab1cc
	void SetMouseCursorWidget(enum class EMouseCursor cursor, struct UUserWidget* CursorWidget); // Function Engine.PlayerController.SetMouseCursorWidget // (Final|Native|Public|BlueprintCallable) // @ game+0x35ab060
	void SetHapticsByValue(float Frequency, float Amplitude, enum class EControllerHand hand); // Function Engine.PlayerController.SetHapticsByValue // (Final|Native|Public|BlueprintCallable) // @ game+0x35aae5c
	void SetDisableHaptics(bool bNewDisabled); // Function Engine.PlayerController.SetDisableHaptics // (Native|Public|BlueprintCallable) // @ game+0x35aadc0
	void SetControllerLightColor(struct FColor Color); // Function Engine.PlayerController.SetControllerLightColor // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x35aad14
	void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning); // Function Engine.PlayerController.SetCinematicMode // (Native|Public|BlueprintCallable) // @ game+0x35aab68
	void SetAudioListenerOverride(struct USceneComponent* AttachToComponent, struct FVector Location, struct FRotator Rotation); // Function Engine.PlayerController.SetAudioListenerOverride // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x35aaa44
	void SetAudioListenerAttenuationOverride(struct USceneComponent* AttachToComponent, struct FVector AttenuationLocationOVerride); // Function Engine.PlayerController.SetAudioListenerAttenuationOverride // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x35aa95c
	void ServerViewSelf(struct FViewTargetTransitionParams TransitionParams); // Function Engine.PlayerController.ServerViewSelf // (Net|Native|Event|Public|NetServer|NetValidate) // @ game+0x35aa88c
	void ServerViewPrevPlayer(); // Function Engine.PlayerController.ServerViewPrevPlayer // (Net|Native|Event|Public|NetServer|NetValidate) // @ game+0x35aa840
	void ServerViewNextPlayer(); // Function Engine.PlayerController.ServerViewNextPlayer // (Net|Native|Event|Public|NetServer|NetValidate) // @ game+0x35aa7f4
	void ServerVerifyViewTarget(); // Function Engine.PlayerController.ServerVerifyViewTarget // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa7a8
	void ServerUpdateMultipleLevelsVisibility(struct TArray<struct FUpdateLevelVisibilityLevelInfo> LevelVisibilities); // Function Engine.PlayerController.ServerUpdateMultipleLevelsVisibility // (Final|Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa6b0
	void ServerUpdateLevelVisibility(struct FUpdateLevelVisibilityLevelInfo LevelVisibility); // Function Engine.PlayerController.ServerUpdateLevelVisibility // (Final|Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa60c
	void ServerUpdateCamera(struct FVector_NetQuantize camLoc, int32_t CamPitchAndYaw); // Function Engine.PlayerController.ServerUpdateCamera // (Net|Native|Event|Public|NetServer|NetValidate) // @ game+0x35aa504
	void ServerUnmutePlayer(struct FUniqueNetIdRepl PlayerId); // Function Engine.PlayerController.ServerUnmutePlayer // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa41c
	void ServerToggleAILogging(); // Function Engine.PlayerController.ServerToggleAILogging // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa3d0
	void ServerShortTimeout(); // Function Engine.PlayerController.ServerShortTimeout // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa384
	void ServerSetSpectatorWaiting(bool bWaiting); // Function Engine.PlayerController.ServerSetSpectatorWaiting // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa2d4
	void ServerSetSpectatorLocation(struct FVector NewLoc, struct FRotator newRot); // Function Engine.PlayerController.ServerSetSpectatorLocation // (Net|Native|Event|Public|NetServer|HasDefaults|NetValidate) // @ game+0x35aa1b0
	void ServerRestartPlayer(); // Function Engine.PlayerController.ServerRestartPlayer // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa164
	void ServerRequestServerTime(struct APlayerController* requester, float requestWorldTime); // Function Engine.PlayerController.ServerRequestServerTime // (Net|NetReliableNative|Event|Protected|NetServer|NetValidate) // @ game+0x35aa074
	void ServerPause(); // Function Engine.PlayerController.ServerPause // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35aa028
	void ServerNotifyLoadedWorld(struct FName WorldPackageName); // Function Engine.PlayerController.ServerNotifyLoadedWorld // (Final|Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9f5c
	void ServerMutePlayer(struct FUniqueNetIdRepl PlayerId); // Function Engine.PlayerController.ServerMutePlayer // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9e74
	void ServerExecRPC(struct FString Msg); // Function Engine.PlayerController.ServerExecRPC // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9dbc
	void ServerExec(struct FString Msg); // Function Engine.PlayerController.ServerExec // (Final|Exec|Native|Public) // @ game+0x161f0f8
	void ServerCheckClientPossessionReliable(); // Function Engine.PlayerController.ServerCheckClientPossessionReliable // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9d70
	void ServerCheckClientPossession(); // Function Engine.PlayerController.ServerCheckClientPossession // (Net|Native|Event|Public|NetServer|NetValidate) // @ game+0x35a9d24
	void ServerChangeName(struct FString S); // Function Engine.PlayerController.ServerChangeName // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9c6c
	void ServerCamera(struct FName NewMode); // Function Engine.PlayerController.ServerCamera // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9bc8
	void ServerAcknowledgePossession(struct APawn* P); // Function Engine.PlayerController.ServerAcknowledgePossession // (Net|NetReliableNative|Event|Public|NetServer|NetValidate) // @ game+0x35a9b28
	void SendToConsole(struct FString Command); // Function Engine.PlayerController.SendToConsole // (Exec|Native|Public) // @ game+0x35a9a94
	void RestartLevel(); // Function Engine.PlayerController.RestartLevel // (Exec|Native|Public) // @ game+0x35a9a7c
	void ResetControllerLightColor(); // Function Engine.PlayerController.ResetControllerLightColor // (Final|Native|Public|BlueprintCallable) // @ game+0x35a9a20
	bool ProjectWorldLocationToScreen(struct FVector WorldLocation, struct FVector2D& ScreenLocation, bool bPlayerViewportRelative); // Function Engine.PlayerController.ProjectWorldLocationToScreen // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a9870
	void PlayHapticEffect(struct UHapticFeedbackEffect_Base* HapticEffect, enum class EControllerHand hand, float Scale, bool bLoop); // Function Engine.PlayerController.PlayHapticEffect // (Final|Native|Public|BlueprintCallable) // @ game+0x35a94bc
	void PlayDynamicForceFeedback(float Intensity, float duration, bool bAffectsLeftLarge, bool bAffectsLeftSmall, bool bAffectsRightLarge, bool bAffectsRightSmall, enum class EDynamicForceFeedbackAction action, struct FLatentActionInfo LatentInfo); // Function Engine.PlayerController.PlayDynamicForceFeedback // (Final|Native|Private|BlueprintCallable) // @ game+0x35a9224
	void Pause(); // Function Engine.PlayerController.Pause // (Exec|Native|Public) // @ game+0x35a8d80
	void OnServerStartedVisualLogger(bool bIsLogging); // Function Engine.PlayerController.OnServerStartedVisualLogger // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a8cfc
	void LocalTravel(struct FString URL); // Function Engine.PlayerController.LocalTravel // (Exec|Native|Public) // @ game+0x35a8c68
	void K2_ClientPlayForceFeedback(struct UForceFeedbackEffect* ForceFeedbackEffect, struct FName Tag, bool bLooping, bool bIgnoreTimeDilation, bool bPlayWhilePaused); // Function Engine.PlayerController.K2_ClientPlayForceFeedback // (Final|Native|Public|BlueprintCallable) // @ game+0x35a8aa0
	bool IsInputKeyDown(struct FKey Key); // Function Engine.PlayerController.IsInputKeyDown // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a89c8
	void GetViewportSize(int32_t& SizeX, int32_t& SizeY); // Function Engine.PlayerController.GetViewportSize // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a88bc
	struct ASpectatorPawn* GetSpectatorPawn(); // Function Engine.PlayerController.GetSpectatorPawn // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a88a4
	bool GetMousePosition(float& LocationX, float& LocationY); // Function Engine.PlayerController.GetMousePosition // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a879c
	struct FVector GetInputVectorKeyState(struct FKey Key); // Function Engine.PlayerController.GetInputVectorKeyState // (Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a86b0
	void GetInputTouchState(enum class ETouchIndex FingerIndex, float& LocationX, float& LocationY, bool& bIsCurrentlyPressed); // Function Engine.PlayerController.GetInputTouchState // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a854c
	void GetInputMouseDelta(float& DeltaX, float& DeltaY); // Function Engine.PlayerController.GetInputMouseDelta // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a847c
	void GetInputMotionState(struct FVector& Tilt, struct FVector& RotationRate, struct FVector& Gravity, struct FVector& Acceleration); // Function Engine.PlayerController.GetInputMotionState // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a8304
	float GetInputKeyTimeDown(struct FKey Key); // Function Engine.PlayerController.GetInputKeyTimeDown // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a8228
	void GetInputAnalogStickState(enum class EControllerAnalogStick WhichStick, float& StickX, float& StickY); // Function Engine.PlayerController.GetInputAnalogStickState // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a8110
	float GetInputAnalogKeyState(struct FKey Key); // Function Engine.PlayerController.GetInputAnalogKeyState // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a8034
	struct AHUD* GetHUD(); // Function Engine.PlayerController.GetHUD // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7814
	bool GetHitResultUnderFingerForObjects(enum class ETouchIndex FingerIndex, struct TArray<enum class EObjectTypeQuery>& ObjectTypes, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderFingerForObjects // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7e9c
	bool GetHitResultUnderFingerByChannel(enum class ETouchIndex FingerIndex, enum class ETraceTypeQuery TraceChannel, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderFingerByChannel // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7d30
	bool GetHitResultUnderFinger(enum class ETouchIndex FingerIndex, enum class ECollisionChannel TraceChannel, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderFinger // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7bc4
	bool GetHitResultUnderCursorForObjects(struct TArray<enum class EObjectTypeQuery>& ObjectTypes, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderCursorForObjects // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7a74
	bool GetHitResultUnderCursorByChannel(enum class ETraceTypeQuery TraceChannel, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderCursorByChannel // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7950
	bool GetHitResultUnderCursor(enum class ECollisionChannel TraceChannel, bool bTraceComplex, struct FHitResult& HitResult); // Function Engine.PlayerController.GetHitResultUnderCursor // (Final|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a782c
	struct FVector GetFocalLocation(); // Function Engine.PlayerController.GetFocalLocation // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a77dc
	void FOV(float NewFOV); // Function Engine.PlayerController.FOV // (Exec|Native|Public) // @ game+0x35a7624
	void EnableCheats(); // Function Engine.PlayerController.EnableCheats // (Exec|Native|Public) // @ game+0x35a760c
	bool DeprojectScreenPositionToWorld(float ScreenX, float ScreenY, struct FVector& WorldLocation, struct FVector& WorldDirection); // Function Engine.PlayerController.DeprojectScreenPositionToWorld // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a74ac
	bool DeprojectMousePositionToWorld(struct FVector& WorldLocation, struct FVector& WorldDirection); // Function Engine.PlayerController.DeprojectMousePositionToWorld // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x35a7394
	void ConsoleKey(struct FKey Key); // Function Engine.PlayerController.ConsoleKey // (Exec|Native|Public) // @ game+0x35a72c4
	void ClientWasKicked(struct FText KickReason); // Function Engine.PlayerController.ClientWasKicked // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a7230
	void ClientVoiceHandshakeComplete(); // Function Engine.PlayerController.ClientVoiceHandshakeComplete // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a7218
	void ClientUpdateMultipleLevelsStreamingStatus(struct TArray<struct FUpdateLevelStreamingLevelStatus> LevelStatuses); // Function Engine.PlayerController.ClientUpdateMultipleLevelsStreamingStatus // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a7184
	void ClientUpdateLevelStreamingStatus(struct FName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad, int32_t LODIndex); // Function Engine.PlayerController.ClientUpdateLevelStreamingStatus // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a6fec
	void ClientUnmutePlayer(struct FUniqueNetIdRepl PlayerId); // Function Engine.PlayerController.ClientUnmutePlayer // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a6f34
	void ClientTravelInternal(struct FString URL, enum class ETravelType TravelType, bool bSeamless, struct FGuid MapPackageGuid); // Function Engine.PlayerController.ClientTravelInternal // (Net|NetReliableNative|Event|Public|HasDefaults|NetClient) // @ game+0x35a6db8
	void ClientTravel(struct FString URL, enum class ETravelType TravelType, bool bSeamless, struct FGuid MapPackageGuid); // Function Engine.PlayerController.ClientTravel // (Final|Native|Public|HasDefaults) // @ game+0x35a6c40
	void ClientTeamMessage(struct APlayerState* SenderPlayerState, struct FString S, struct FName Type, float MsgLifeTime); // Function Engine.PlayerController.ClientTeamMessage // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a6ae0
	void ClientStopForceFeedback(struct UForceFeedbackEffect* ForceFeedbackEffect, struct FName Tag); // Function Engine.PlayerController.ClientStopForceFeedback // (Net|NetReliableNative|Event|Public|NetClient|BlueprintCallable) // @ game+0x35a6a18
	void ClientStopCameraShakesFromSource(struct UCameraShakeSourceComponent* SourceComponent, bool bImmediately); // Function Engine.PlayerController.ClientStopCameraShakesFromSource // (Final|Native|Public|BlueprintCallable) // @ game+0x35a694c
	void ClientStopCameraShake(struct UCameraShakeBase* Shake, bool bImmediately); // Function Engine.PlayerController.ClientStopCameraShake // (Net|NetReliableNative|Event|Public|NetClient|BlueprintCallable) // @ game+0x35a6880
	void ClientStopCameraAnim(struct UCameraAnim* AnimToStop); // Function Engine.PlayerController.ClientStopCameraAnim // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a67fc
	void ClientStartOnlineSession(); // Function Engine.PlayerController.ClientStartOnlineSession // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a67e4
	void ClientStartCameraShakeFromSource(struct UCameraShakeBase* Shake, struct UCameraShakeSourceComponent* SourceComponent); // Function Engine.PlayerController.ClientStartCameraShakeFromSource // (Final|Native|Public|BlueprintCallable) // @ game+0x35a66ec
	void ClientStartCameraShake(struct UCameraShakeBase* Shake, float Scale, enum class ECameraShakePlaySpace PlaySpace, struct FRotator UserPlaySpaceRot); // Function Engine.PlayerController.ClientStartCameraShake // (Net|Native|Event|Public|HasDefaults|NetClient|BlueprintCallable) // @ game+0x35a6594
	void ClientSpawnCameraLensEffect(struct AEmitterCameraLensEffectBase* LensEffectEmitterClass); // Function Engine.PlayerController.ClientSpawnCameraLensEffect // (Net|Native|Event|Public|NetClient|BlueprintCallable) // @ game+0x35a6510
	void ClientSetViewTarget(struct AActor* A, struct FViewTargetTransitionParams TransitionParams); // Function Engine.PlayerController.ClientSetViewTarget // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a6420
	void ClientSetSpectatorWaiting(bool bWaiting); // Function Engine.PlayerController.ClientSetSpectatorWaiting // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a639c
	void ClientSetHUD(struct AHUD* NewHUDClass); // Function Engine.PlayerController.ClientSetHUD // (Net|NetReliableNative|Event|Public|NetClient|BlueprintCallable) // @ game+0x1db9ccc
	void ClientSetForceMipLevelsToBeResident(struct UMaterialInterface* Material, float ForceDuration, int32_t CinematicTextureGroups); // Function Engine.PlayerController.ClientSetForceMipLevelsToBeResident // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a629c
	void ClientSetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD); // Function Engine.PlayerController.ClientSetCinematicMode // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a6144
	void ClientSetCameraMode(struct FName NewCamMode); // Function Engine.PlayerController.ClientSetCameraMode // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a60c0
	void ClientSetCameraFade(bool bEnableFading, struct FColor FadeColor, struct FVector2D FadeAlpha, float FadeTime, bool bFadeAudio, bool bHoldWhenFinished); // Function Engine.PlayerController.ClientSetCameraFade // (Net|NetReliableNative|Event|Public|HasDefaults|NetClient) // @ game+0x35a5ee4
	void ClientSetBlockOnAsyncLoading(); // Function Engine.PlayerController.ClientSetBlockOnAsyncLoading // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5ecc
	void ClientReturnToMainMenuWithTextReason(struct FText ReturnReason); // Function Engine.PlayerController.ClientReturnToMainMenuWithTextReason // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5e38
	void ClientReturnToMainMenu(struct FString ReturnReason); // Function Engine.PlayerController.ClientReturnToMainMenu // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5da4
	void ClientRetryClientRestart(struct APawn* NewPawn); // Function Engine.PlayerController.ClientRetryClientRestart // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x1d49080
	void ClientRestart(struct APawn* NewPawn); // Function Engine.PlayerController.ClientRestart // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x1db9fcc
	void ClientReset(); // Function Engine.PlayerController.ClientReset // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5d8c
	void ClientReportServerTime(float requestWorldTime, float serverTime); // Function Engine.PlayerController.ClientReportServerTime // (Net|NetReliableNative|Event|Protected|NetClient) // @ game+0x35a5cc4
	void ClientRepObjRef(struct UObject* Object); // Function Engine.PlayerController.ClientRepObjRef // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x1d74f3c
	void ClientReceiveLocalizedMessage(struct ULocalMessage* Message, int32_t SWITCH, struct APlayerState* RelatedPlayerState_2, struct APlayerState* RelatedPlayerState_3, struct UObject* OptionalObject); // Function Engine.PlayerController.ClientReceiveLocalizedMessage // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5b3c
	void ClientPrestreamTextures(struct AActor* ForcedActor, float ForceDuration, bool bEnableStreaming, int32_t CinematicTextureGroups); // Function Engine.PlayerController.ClientPrestreamTextures // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a59f4
	void ClientPrepareMapChange(struct FName LevelName, bool bFirst, bool bLast); // Function Engine.PlayerController.ClientPrepareMapChange // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a58f4
	void ClientPlaySoundAtLocation(struct USoundBase* Sound, struct FVector Location, float VolumeMultiplier, float PitchMultiplier); // Function Engine.PlayerController.ClientPlaySoundAtLocation // (Net|Native|Event|Public|HasDefaults|NetClient) // @ game+0x35a57a0
	void ClientPlaySound(struct USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier); // Function Engine.PlayerController.ClientPlaySound // (Net|Native|Event|Public|NetClient) // @ game+0x35a56a4
	void ClientPlayForceFeedback_Internal(struct UForceFeedbackEffect* ForceFeedbackEffect, struct FForceFeedbackParameters Params); // Function Engine.PlayerController.ClientPlayForceFeedback_Internal // (Final|Net|Native|Event|Private|NetClient) // @ game+0x35a55c0
	void ClientPlayCameraAnim(struct UCameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float blendOutTime, bool bLoop, bool bRandomStartTime, enum class ECameraShakePlaySpace Space, struct FRotator CustomPlaySpace); // Function Engine.PlayerController.ClientPlayCameraAnim // (Net|Native|Event|Public|HasDefaults|NetClient|BlueprintCallable) // @ game+0x35a5300
	void ClientNotifyServerTimeChanged(); // Function Engine.PlayerController.ClientNotifyServerTimeChanged // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a52e8
	void ClientMutePlayer(struct FUniqueNetIdRepl PlayerId); // Function Engine.PlayerController.ClientMutePlayer // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5230
	void ClientMessage(struct FString S, struct FName Type, float MsgLifeTime); // Function Engine.PlayerController.ClientMessage // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a510c
	void ClientIgnoreMoveInput(bool bIgnore); // Function Engine.PlayerController.ClientIgnoreMoveInput // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5088
	void ClientIgnoreLookInput(bool bIgnore); // Function Engine.PlayerController.ClientIgnoreLookInput // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a5004
	void ClientGotoState(struct FName newState); // Function Engine.PlayerController.ClientGotoState // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4f80
	void ClientGameEnded(struct AActor* EndGameFocus, bool bIsWinner); // Function Engine.PlayerController.ClientGameEnded // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4eb4
	void ClientForceGarbageCollection(); // Function Engine.PlayerController.ClientForceGarbageCollection // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4e9c
	void ClientFlushLevelStreaming(); // Function Engine.PlayerController.ClientFlushLevelStreaming // (Final|Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4e4c
	void ClientEndOnlineSession(); // Function Engine.PlayerController.ClientEndOnlineSession // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4e34
	void ClientEnableNetworkVoice(bool bEnable); // Function Engine.PlayerController.ClientEnableNetworkVoice // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4db0
	void ClientCommitMapChange(); // Function Engine.PlayerController.ClientCommitMapChange // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4d98
	void ClientClearCameraLensEffects(); // Function Engine.PlayerController.ClientClearCameraLensEffects // (Net|NetReliableNative|Event|Public|NetClient|BlueprintCallable) // @ game+0x35a4d80
	void ClientCapBandwidth(int32_t Cap); // Function Engine.PlayerController.ClientCapBandwidth // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4cfc
	void ClientCancelPendingMapChange(); // Function Engine.PlayerController.ClientCancelPendingMapChange // (Net|NetReliableNative|Event|Public|NetClient) // @ game+0x35a4ce4
	void ClientAddTextureStreamingLoc(struct FVector InLoc, float duration, bool bOverrideLocation); // Function Engine.PlayerController.ClientAddTextureStreamingLoc // (Final|Net|NetReliableNative|Event|Public|HasDefaults|NetClient) // @ game+0x35a4bd8
	void ClearAudioListenerOverride(); // Function Engine.PlayerController.ClearAudioListenerOverride // (Final|Native|Public|BlueprintCallable) // @ game+0x35a4bc4
	void ClearAudioListenerAttenuationOverride(); // Function Engine.PlayerController.ClearAudioListenerAttenuationOverride // (Final|Native|Public|BlueprintCallable) // @ game+0x35a4b88
	bool CanRestartPlayer(); // Function Engine.PlayerController.CanRestartPlayer // (Native|Public|BlueprintCallable) // @ game+0x1db9b74
	void Camera(struct FName NewMode); // Function Engine.PlayerController.Camera // (Exec|Native|Public) // @ game+0x35a4b04
	void AddYawInput(float Val); // Function Engine.PlayerController.AddYawInput // (Native|Public|BlueprintCallable) // @ game+0x35a4a7c
	void AddRollInput(float Val); // Function Engine.PlayerController.AddRollInput // (Native|Public|BlueprintCallable) // @ game+0x35a49f4
	void AddPitchInput(float Val); // Function Engine.PlayerController.AddPitchInput // (Native|Public|BlueprintCallable) // @ game+0x35a496c
	void ActivateTouchInterface(struct UTouchInterface* NewTouchInterface); // Function Engine.PlayerController.ActivateTouchInterface // (Native|Public|BlueprintCallable) // @ game+0x35a47c0
};

// Class Engine.Pawn
// Size: 0x2b8 (Inherited: 0x248)
struct APawn : AActor {
	char pad_00[0x70];
};

// Class Engine.Character
// Size: 0x540 (Inherited: 0x2b8)
struct ACharacter : APawn {
	char pad_00[0x288];
};

struct UScriptViewportClient : UObject {
	char pad_28[0x10]; // 0x28(0x10)
};

struct UGameViewportClient : UScriptViewportClient {
	char pad_38[0x8]; // 0x38(0x08)
	struct UConsole* ViewportConsole; // 0x40(0x08)
	struct TArray<struct FDebugDisplayProperty> DebugProperties; // 0x48(0x10)
	char pad_58[0x10]; // 0x58(0x10)
	int32_t MaxSplitscreenPlayers; // 0x68(0x04)
	char pad_6C[0xc]; // 0x6c(0x0c)
	struct UWorld* World; // 0x78(0x08)
	struct UGameInstance* GameInstance; // 0x80(0x08)
	char pad_88[0x2f8]; // 0x88(0x2f8)

	void SSSwapControllers(); // Function Engine.GameViewportClient.SSSwapControllers // (Exec|Native|Public) // @ game+0x2672580
	void ShowTitleSafeArea(); // Function Engine.GameViewportClient.ShowTitleSafeArea // (Exec|Native|Public) // @ game+0x2672598
	void SetConsoleTarget(int32_t PlayerIndex); // Function Engine.GameViewportClient.SetConsoleTarget // (Exec|Native|Public) // @ game+0x35011b0
};

struct UPlayer : UObject {
	char pad_28[0x8]; // 0x28(0x08)
	struct APlayerController* PlayerController; // 0x30(0x08)
	int CurrentNetSpeed; // 0x38(0x04)
	int ConfiguredInternetSpeed; // 0x3c(0x04)
	int ConfiguredLanSpeed; // 0x40(0x04)
	char pad_44[0x4]; // 0x44(0x04)
};

struct ULocalPlayer : UPlayer {
	char pad_48[0x28]; // 0x48(0x28)
	struct UGameViewportClient* ViewportClient; // 0x70(0x08)
	char pad_78[0x1c]; // 0x78(0x1c)
	char AspectRatioAxisConstraint; // 0x94(0x01)
	char pad_95[0x3]; // 0x95(0x03)
	struct APlayerController* PendingLevelPlayerControllerClass; // 0x98(0x08)
	char bSentSplitJoin : 1; // 0xa0(0x01)
	char pad_A0_1 : 7; // 0xa0(0x01)
	char pad_A1[0x17]; // 0xa1(0x17)
	int ControllerId; // 0xb8(0x04)
	char pad_BC[0x19c]; // 0xbc(0x19c)
};

struct UGameInstance : UObject {
	char pad_28[0x10]; // 0x28(0x10)
	struct TArray<struct ULocalPlayer*> LocalPlayers; // 0x38(0x10)
	struct UOnlineSession* OnlineSession; // 0x48(0x08)
	struct TArray<struct UObject*> ReferencedObjects; // 0x50(0x10)
	char pad_60[0x18]; // 0x60(0x18)
	char OnPawnControllerChangedDelegates[0x10]; // 0x78(0x10)
	char pad_88[0x120]; // 0x88(0x120)
};

// Class OPP.RBPawn
// Size: 0x4d70 (Inherited: 0x540)
struct ARBPawn : ACharacter {
	char pad_00[0x4830];
};

// Class OPP.RBPlayer
// Size: 0x7520 (Inherited: 0x4d70)
struct ARBPlayer : ARBPawn {
	char pad_00[0x13D8];
	float stamina; // 0x6148(0x04)
	char pad_614C[0xc]; // 0x614c(0x0c)
	struct TArray<struct FStaminaRestoreData> StaminaRestoreData; // 0x6158(0x10)
	char pad_6168[0x8]; // 0x6168(0x08)
	struct TArray<float> DamageBoostPawnTimestamps; // 0x6170(0x10)
	char pad_6180[0x8]; // 0x6180(0x08)
	struct URBSoundComponent* WatchAKComponent; // 0x6188(0x08)
	struct URBSoundComponent* OverridePrimeAssetVOComponent; // 0x6190(0x08)
	float CurrentVisualDetectionMeter; // 0x6198(0x04)
	float CurrentAudioDetectionMeter; // 0x619c(0x04)
	float UINoiseMeter; // 0x61a0(0x04)
	char UINoiseMeterStrength; // 0x61a4(0x01)
	char pad_61A5[0x13]; // 0x61a5(0x13)
	float NightHunterNVInterference; // 0x61b8(0x04)
	bool bHasBotAwareOfPlayer; // 0x61bc(0x01)
	char pad_61BD[0x7]; // 0x61bd(0x07)
	float LastBotAwareTimeStamp_Server; // 0x61c4(0x04)
	struct TArray<struct ARBNPC*> ChaseNPCs; // 0x61c8(0x10)
	char pad_61D8[0x10]; // 0x61d8(0x10)
	struct TArray<struct FName> PreviousActiveEffectTrackingDataEntries; // 0x61e8(0x10)
	struct TArray<struct FActiveEffectTrackingData> activeEffectTrackingDataEntries; // 0x61f8(0x10)
	bool bAutoHealthRegenInProgress; // 0x6208(0x01)
	char pad_6209[0x7]; // 0x6209(0x07)
	char OnAutoHealthRegenEnded[0x10]; // 0x6210(0x10)
	char OnInventorySizeChanged[0x10]; // 0x6220(0x10)
	char pad_6230[0x18]; // 0x6230(0x18)
	struct URBAimAssistComponent* ThrowAimAssistTargetComp; // 0x6248(0x08)
	struct UCurveFloat* WakeUpEyeCurve; // 0x6250(0x08)
	struct AActor* FistItemClass; // 0x6258(0x08)
	char Memory[0x64]; // 0x6260(0x64)
	char pad_62C4[0x1c]; // 0x62c4(0x1c)
	struct TArray<struct UObject*> CachedCustomizationResources; // 0x62e0(0x10)
	char pad_62F0[0x70]; // 0x62f0(0x70)
	struct ARBPickup* ItemToDrop; // 0x6360(0x08)
	char pad_6368[0x8]; // 0x6368(0x08)
	char ItemToDropTargetTransform[0x30]; // 0x6370(0x30)
	char pad_63A0[0x38]; // 0x63a0(0x38)
	int32_t NumberOfTimeKnockedDown; // 0x63d8(0x04)
	bool bIsPushingObjectiveCart; // 0x63dc(0x01)
	bool bIsStalkingTarget; // 0x63dd(0x01)
	bool bIsInteractingWithHighProrityObjective; // 0x63de(0x01)
	bool bIsCompletingObjective_Client; // 0x63df(0x01)
	bool bIgnorePlayerToPlayerCollisions; // 0x63e0(0x01)
	char pad_63E1[0x3]; // 0x63e1(0x03)
	float EnvironmentLightingIntensity; // 0x63e4(0x04)
	struct URBPuzzleRoomComponent* ActivePuzzleRoom; // 0x63e8(0x08)
	char pad_63F0[0x28]; // 0x63f0(0x28)
	struct URBPlayerCamera* Camera; // 0x6418(0x08)
	struct URBPlayerCameraLocationComponent* PlayerCameraComponent; // 0x6420(0x08)
	char pad_6428[0x228]; // 0x6428(0x228)
	char MaxNVBattery[0x30]; // 0x6650(0x30)
	char pad_6680[0x64]; // 0x6680(0x64)
	float NVBattery; // 0x66e4(0x04)
	char bIsNVActive[0x70]; // 0x66e8(0x70)
	char bWantsNVActive[0x70]; // 0x6758(0x70)
	char LastConsumedBatteryType; // 0x67c8(0x01)
	char pad_67C9[0xb]; // 0x67c9(0x0b)
	float NVAnimationDuration; // 0x67d4(0x04)
	float NVAnimationRatio; // 0x67d8(0x04)
	float NVAnimationTargetRatio; // 0x67dc(0x04)
	char CurrentGoggleNVAnim[0x30]; // 0x67e0(0x30)
	char CurrentArmNVAnim[0x30]; // 0x6810(0x30)
	bool bNVAnimationActive; // 0x6840(0x01)
	char pad_6841[0x337]; // 0x6841(0x337)
	char NoiseTrapNoiseMultiplier[0x30]; // 0x6b78(0x30)
	char pad_6BA8[0x2d0]; // 0x6ba8(0x2d0)
	struct USkeletalMeshComponent* RigSkeletalMeshComp; // 0x6e78(0x08)
	struct USkeletalMeshComponent* CustomActionSkeletalMeshComp; // 0x6e80(0x08)
	struct USceneComponent* EyeLocationComp; // 0x6e88(0x08)
	struct URBNVComponent* NVComponent; // 0x6e90(0x08)
	struct USpotLightComponent* ProximityLight; // 0x6e98(0x08)
	struct USpotLightComponent* SpecLight; // 0x6ea0(0x08)
	struct ARBActiveSkill* activeSkillActor; // 0x6ea8(0x08)
	float DefaultProximityLightInsensity; // 0x6eb0(0x04)
	float HiddenProximityLightInsensity; // 0x6eb4(0x04)
	struct URBAnimInstance* AnimInstanceClass1P; // 0x6eb8(0x08)
	struct URBAnimInstance* AnimInstanceClass3P; // 0x6ec0(0x08)
	char pad_6EC8[0x8]; // 0x6ec8(0x08)
	char InfiniteStaminaPostProcessSettings[0x5b0]; // 0x6ed0(0x5b0)
	int32_t InfiniteStaminaEffectPriority; // 0x7480(0x04)
	bool bUseInfiniteStaminaEffect; // 0x7484(0x01)
	char pad_7485[0x3]; // 0x7485(0x03)
	struct ARBHUD* RBHUD; // 0x7488(0x08)
	char pad_7490[0x14]; // 0x7490(0x14)
	bool bDebugChase; // 0x74a4(0x01)
	char pad_74A5[0xb]; // 0x74a5(0x0b)
	struct URBSASChairPanelComponent* ReservedSASChair_Server; // 0x74b0(0x08)
	struct ARBController* RBController; // 0x74b8(0x08)
	bool bIsAssociatedPlayerConnected; // 0x74c0(0x01)
	bool bIsControlledByGameMode; // 0x74c1(0x01)
	char pad_74C2[0x6]; // 0x74c2(0x06)
	struct FString FullPlayerName; // 0x74c8(0x10)
	struct ARBCrouchUnderMarker* InsideCrouchUnderMarker; // 0x74d8(0x08)
	char pad_74E0[0x30]; // 0x74e0(0x30)
	struct ARBPlayerStart* ForcedWakeUpPlayerStart; // 0x7510(0x08)
	char pad_7518[0x8]; // 0x7518(0x08)

	struct FString GetGamePlayerName(); // Function OPP.RBPlayer.GetGamePlayerName // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1dca528
};

// Enum OPP.ENPCType
enum class ENPCType : uint8_t {
	Grunt = 0,
	Ambient = 1,
	BigGrunt = 2,
	PitcherSniper = 3,
	SleeperScreamer = 4,
	Pouncer = 5,
	Pusher = 6,
	GroundPitcher = 7,
	Berserker = 8,
	Imposter = 9,
	NightHunter = 10,
	Spectre = 11,
	ThrowableTarget = 12,
	StalkerTarget = 13,
	Gooseberry = 14,
	Coyle = 15,
	Scientist = 16,
	Guard = 17,
	MAX = 18
};

// Class OPP.RBNPC
// Size: 0x55b0 (Inherited: 0x4d70)
struct ARBNPC : ARBPawn {
	enum class ENPCType NPCType; // 0x4d70(0x01)
	char pad_4D71[0x7]; // 0x4d71(0x07)
	char NPCTags[0x20]; // 0x4d78(0x20)
	char Capabilities[0x15]; // 0x4d98(0x15)
	char pad_4DAD[0x3]; // 0x4dad(0x03)
	char PathfindingCosts[0x34]; // 0x4db0(0x34)
	float WallSeparationCheckDistance; // 0x4de4(0x04)
	float WallSeparationCapsuleRadius; // 0x4de8(0x04)
	char pad_4DEC[0x4]; // 0x4dec(0x04)
	char FootstepCameraShakeData[0xa0]; // 0x4df0(0xa0)
	struct URBAnimReferences* H1AnimRefsAsset; // 0x4e90(0x08)
	struct URBAnimReferences* H2AnimRefsAsset; // 0x4e98(0x08)
	struct UAnimBlueprint* WeaponAnimBP; // 0x4ea0(0x08)
	struct TArray<struct URBVOMapping*> VOMappingOptions; // 0x4ea8(0x10)
	struct URBNPCWeaponList* WeaponList; // 0x4eb8(0x08)
	struct AActor* PsychosisMineClass; // 0x4ec0(0x08)
	float WaterMaxSlowDownRatio; // 0x4ec8(0x04)
	float WaterDepthMinSlowDownStart; // 0x4ecc(0x04)
	float WaterDepthMaxSlowDownStart; // 0x4ed0(0x04)
	char pad_4ED4[0x4]; // 0x4ed4(0x04)
	char PendingInterruptionAction[0x28]; // 0x4ed8(0x28)
	char OnAIEvent[0x10]; // 0x4f00(0x10)
	char OnHitByProjectile[0x10]; // 0x4f10(0x10)
	char OnPlayWeaponAnimation[0x10]; // 0x4f20(0x10)
	struct ARBBot* bot; // 0x4f30(0x08)
	struct URBBotVision* Vision; // 0x4f38(0x08)
	char NPCConfig[0x20]; // 0x4f40(0x20)
	struct FString NPCName; // 0x4f60(0x10)
	uint16_t NPCId; // 0x4f70(0x02)
	char pad_4F72[0x2]; // 0x4f72(0x02)
	float GroundSpeed; // 0x4f74(0x04)
	char pad_4F78[0x8]; // 0x4f78(0x08)
	char attackParams[0x30]; // 0x4f80(0x30)
	struct TArray<struct FDelayedVO> DelayedVOs; // 0x4fb0(0x10)
	char WeaponConfig[0x18]; // 0x4fc0(0x18)
	char Weapon[0x03]; // 0x4fd8(0x03)
	char pad_4FDB[0x5]; // 0x4fdb(0x05)
	struct ARBNPCWeapon* NPCWeapon; // 0x4fe0(0x08)
	char UnarmedRightHandStrikeSoundMaterial; // 0x4fe8(0x01)
	char UnarmedLeftHandStrikeSoundMaterial; // 0x4fe9(0x01)
	char UnarmedHeadStrikeSoundMaterial; // 0x4fea(0x01)
	char UnarmedLeftFootStrikeSoundMaterial; // 0x4feb(0x01)
	char UnarmedRightFootStrikeSoundMaterial; // 0x4fec(0x01)
	char UnarmedOtherStrikeSoundMaterial; // 0x4fed(0x01)
	char pad_4FEE[0x2]; // 0x4fee(0x02)
	struct USphereComponent* LeftHandDamageVolume; // 0x4ff0(0x08)
	struct UCapsuleComponent* RightHandDamageCapsule; // 0x4ff8(0x08)
	struct USphereComponent* LeftFootDamageVolume; // 0x5000(0x08)
	struct USphereComponent* RightFootDamageVolume; // 0x5008(0x08)
	struct UNiagaraComponent* NightHunterSparksEmitter; // 0x5010(0x08)
	struct UNiagaraComponent* WeaponVFXEmitter; // 0x5018(0x08)
	struct UPointLightComponent* WeaponVFXLight; // 0x5020(0x08)
	struct UCapsuleComponent* IdleCollision; // 0x5028(0x08)
	char InvestigationData[0x28]; // 0x5030(0x28)
	char AmbientData[0x14]; // 0x5058(0x14)
	char pad_506C[0x4]; // 0x506c(0x04)
	char ReplicatedAmbientData[0x10]; // 0x5070(0x10)
	char LookAtConfig[0x20]; // 0x5080(0x20)
	char LookAt[0x48]; // 0x50a0(0x48)
	char turnOnSpot[0x10]; // 0x50e8(0x10)
	char Waypoint[0x10]; // 0x50f8(0x10)
	char AnimatedStart[0x48]; // 0x5108(0x48)
	char AnimatedStop[0x88]; // 0x5150(0x88)
	char Startle[0x48]; // 0x51d8(0x48)
	char LongJump[0x44]; // 0x5220(0x44)
	char Ceiling[0x18]; // 0x5264(0x18)
	char pad_527C[0x4]; // 0x527c(0x04)
	char DoorInteractionData[0xa8]; // 0x5280(0xa8)
	char doorInvParams[0x30]; // 0x5328(0x30)
	char WeaponVFXAnimControl[0x18]; // 0x5358(0x18)
	char WeaponVFX[0x14]; // 0x5370(0x14)
	bool bIsAffectedByGrenadeStun; // 0x5384(0x01)
	bool bIsAffectedByBlindPaint; // 0x5385(0x01)
	char pad_5386[0x2]; // 0x5386(0x02)
	struct TArray<int32_t> AffectedBlindPaintDeploymentIdList; // 0x5388(0x10)
	char Breadcrumbs[0x20]; // 0x5398(0x20)
	char LoopingIdle[0x18]; // 0x53b8(0x18)
	char ScriptedAnim[0x18]; // 0x53d0(0x18)
	char LocalScriptedAnimData[0x18]; // 0x53e8(0x18)
	char BotActivity; // 0x5400(0x01)
	char BotAwarenessState; // 0x5401(0x01)
	char pad_5402[0x2]; // 0x5402(0x02)
	float BotAwarenessStateMeter; // 0x5404(0x04)
	char AnimStyle; // 0x5408(0x01)
	bool ServerPlayingAnimations; // 0x5409(0x01)
	bool bNoTickPose; // 0x540a(0x01)
	bool bNoRefreshBoneTransforms; // 0x540b(0x01)
	char pad_540C[0x4]; // 0x540c(0x04)
	float PlayerDetectionAlpha; // 0x5410(0x04)
	bool bAllowPlayerPing; // 0x5414(0x01)
	char CurrentContinousVOClientState; // 0x5415(0x01)
	char CurrentContinousFoleyClientState; // 0x5416(0x01)
	char pad_5417[0x1]; // 0x5417(0x01)
	struct UAkAudioEvent* AmbientSoundStopEvent; // 0x5418(0x08)
	char pad_5420[0x20]; // 0x5420(0x20)
	struct ARBPlayer* SpectreTargetPlayer; // 0x5440(0x08)
	bool bSpectreSpook; // 0x5448(0x01)
	char pad_5449[0x7]; // 0x5449(0x07)
	char bCanShowSpectre[0x70]; // 0x5450(0x70)
	bool bShouldShowSpectre; // 0x54c0(0x01)
	char SpectreVisualType; // 0x54c1(0x01)
	char pad_54C2[0xe]; // 0x54c2(0x0e)
	char NPCFlavor; // 0x54d0(0x01)
	char pad_54D1[0x7]; // 0x54d1(0x07)
	struct ARBPlayer* SpecificTarget; // 0x54d8(0x08)
	struct ARBAISpawner* spawner; // 0x54e0(0x08)
	struct UObject* SpawnSentinel; // 0x54e8(0x08)
	char NPCHitReaction[0x38]; // 0x54f0(0x38)
	char pad_5528[0x10]; // 0x5528(0x10)
	struct AActor* SpecialMoveOrientationActor; // 0x5538(0x08)
	char pad_5540[0x4]; // 0x5540(0x04)
	float PassingDoorTimestamp; // 0x5544(0x04)
	struct ARBBasePushable* TraversalPushable; // 0x5548(0x08)
	char pad_5550[0x12]; // 0x5550(0x12)
	bool bAccelerateCrouchUnder; // 0x5562(0x01)
	char pad_5563[0x2]; // 0x5563(0x02)
	bool bCanBeStalked; // 0x5565(0x01)
	char pad_5566[0x2]; // 0x5566(0x02)
	struct URBVOMapping* VOMappingAsset; // 0x5568(0x08)
	struct URBVOMappingOverride* VOMappingOverrides; // 0x5570(0x08)
	struct FString VoiceType; // 0x5578(0x10)
	bool bVoiceTypeLoaded; // 0x5588(0x01)
	char pad_5589[0x7]; // 0x5589(0x07)
	struct FString PreparedVoiceType; // 0x5590(0x10)
	struct URBHidespotComponent* LastHiddenHidespot; // 0x55a0(0x08)
	char pad_55A8[0x8]; // 0x55a8(0x08)
};

// Class OPP.RBActor
// Size: 0x250 (Inherited: 0x248)
struct ARBActor : AActor {
	bool bAllowAttachmentReplication; // 0x248(0x01)
	char pad_249[0x7]; // 0x249(0x07)
};

// Class OPP.RBArmWreslingPanelComponent
// Size: 0x8a0 (Inherited: 0x7a0)
struct URBArmWreslingPanelComponent : UObject {
	char pad_00[0x778];
	char pad_7A0[0x8]; // 0x7a0(0x08)
	char MashInteractionText[0x18]; // 0x7a8(0x18)
	int32_t MaxConsecutiveHitsForZoneSize; // 0x7c0(0x04)
	float HitSuccessPushAmount; // 0x7c4(0x04)
	float HitFailPenalty; // 0x7c8(0x04)
	int32_t NumScoringSteps; // 0x7cc(0x04)
	char HitZoneMultipliers[0x10]; // 0x7d0(0x10)
	int32_t CursorRevolutionCount; // 0x7e0(0x04)
	float SuccessZoneSize; // 0x7e4(0x04)
	float SuccessZoneSizeMin; // 0x7e8(0x04)
	float SuccessZoneSizeMax; // 0x7ec(0x04)
	float SuccessZoneOffset; // 0x7f0(0x04)
	int32_t HitZoneIndex; // 0x7f4(0x04)
	int32_t MaxRevolutions; // 0x7f8(0x04)
	float CursorStartSpeed; // 0x7fc(0x04)
	float CursorMaxSpeed; // 0x800(0x04)
	float CursorSpeedIncreasePerRevolution; // 0x804(0x04)
	int32_t NumRevolutionsUntilMaxSpeed; // 0x808(0x04)
	float CursorWidth; // 0x80c(0x04)
	float InitialRevolutionCursorSpeed; // 0x810(0x04)
	float FakePlayerSuccessRate; // 0x814(0x04)
	struct FVector2D GameTimeCameraYawLimit; // 0x818(0x08)
	struct FVector2D GameTimeCameraPitchLimit; // 0x820(0x08)
	struct FVector2D WaitingCameraYawLimit; // 0x828(0x08)
	struct FVector2D WaitingCameraPitchLimit; // 0x830(0x08)
	float TauntMinimumInterval; // 0x838(0x04)
	char pad_83C[0x4]; // 0x83c(0x04)
	struct ARBArmWreslingTable* LinkedTable; // 0x840(0x08)
	float MatchStartPawnTime; // 0x848(0x04)
	float MatchStartServerTime; // 0x84c(0x04)
	char InputSuccessCallback[0x10]; // 0x850(0x10)
	char InputFailCallback[0x10]; // 0x860(0x10)
	char UpdateEndZoneCallback[0x10]; // 0x870(0x10)
	char TauntCallback[0x10]; // 0x880(0x10)
	char pad_890[0x10]; // 0x890(0x10)

	bool IsArmWreslingRoundInProgress(); // Function OPP.RBArmWreslingPanelComponent.IsArmWreslingRoundInProgress // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d0c260
	float GetCursorPosition(); // Function OPP.RBArmWreslingPanelComponent.GetCursorPosition // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d0c09c
};


// Class OPP.RBArmWreslingTable
// Size: 0x3e0 (Inherited: 0x248)
struct ARBArmWreslingTable : AActor {
	float SuccessZoneOffsetMin; // 0x248(0x04)
	float SuccessZoneOffsetMax; // 0x24c(0x04)
	char player1RoundData[0x38]; // 0x250(0x38)
	char player2RoundData[0x38]; // 0x288(0x38)
	struct TArray<float> SuccessZoneOffsets; // 0x2c0(0x10)
	char Player1PanelActor[0x28]; // 0x2d0(0x28)
	char Player2PanelActor[0x28]; // 0x2f8(0x28)
	float MatchIntroTime; // 0x320(0x04)
	float MatchOutroTime; // 0x324(0x04)
	struct URBArmWreslingPanelComponent* Player1Panel; // 0x328(0x08)
	struct URBArmWreslingPanelComponent* Player2Panel; // 0x330(0x08)
	float MatchStartTimestamp; // 0x338(0x04)
	float MatchEndTimestamp; // 0x33c(0x04)
	struct ARBPlayer* Winner; // 0x340(0x08)
	struct ARBPlayer* Loser; // 0x348(0x08)
	struct ARBPlayer* Player1; // 0x350(0x08)
	struct ARBPlayer* Player2; // 0x358(0x08)
	float Player1WinRatio; // 0x360(0x04)
	bool bRoundCompleted; // 0x364(0x01)
	bool bGameTied; // 0x365(0x01)
	char pad_366[0x12]; // 0x366(0x12)
	char OnPlayerInputCallback[0x10]; // 0x378(0x10)
	char OnTableStateChanged[0x10]; // 0x388(0x10)
	char OnWinningRatioPerPointChanged[0x10]; // 0x398(0x10)
	char OnPlayerConnectedCallback[0x10]; // 0x3a8(0x10)
	char OnPlayerDisconnectedCallback[0x10]; // 0x3b8(0x10)
	char OnRoundEndedCallback[0x10]; // 0x3c8(0x10)
	char pad_3D8[0x8]; // 0x3d8(0x08)

	struct URBArmWreslingPanelComponent* GetLocallyWatchedPanel(); // Function OPP.RBArmWreslingTable.GetLocallyWatchedPanel // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d0c160
};

// Class OPP.RBInteractiblePanelComponent
// Size: 0x7a0 (Inherited: 0x600)
struct URBInteractiblePanelComponent {
	char pad_00[0x600]; // 0x600
	char pad_02[0x101];
	bool bPanelInUse; // 0x701(0x01)
	char pad_01[0x9F];
	//bool IsPanelActive(); // Function OPP.RBInteractiblePanelComponent.IsPanelActive // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1d83f8c
};

// Enum OPP.EHackQuadrantState
enum class EHackQuadrantState : uint8_t {
	Failure = 0,
	Neutral = 1,
	Success = 2,
	EHackQuadrantState_MAX = 3
};

// Class OPP.RBHackPanelComponent
// Size: 0x1300 (Inherited: 0x7a0)
struct URBHackPanelComponent : URBInteractiblePanelComponent {
	char pad_00[0x898];
	int32_t NumberOfQuadrant; // 0x1038(0x04)
	char pad_01[0xF8];
	struct TArray<enum class EHackQuadrantState> QuadrantStates; // 0x1130(0x10)
	char pad_1140[0x10]; // 0x1140(0x10)
	float needleRatio; // 0x1150(0x04)
	char pad_02[0x1B0];
};

// Class OPP.RBInteractibleContainer
// Size: 0x4d0 (Inherited: 0x300)
struct ARBInteractibleContainer {
	char pad_00[0x300];
	char pad_300[0x1C0]; // 0x300(0x70)
	struct URBHackPanelComponent* HackPanel; // 0x4c0(0x08)
	char pad_4C8[0x8]; // 0x4c8(0x08)
};

// Class OPP.RBPickup
// Size: 0x9d0 (Inherited: 0x250)
struct ARBPickup : ARBActor {
	char pad_250[0x18]; // 0x250(0x18)
	struct URBInteractionZoneComponent* InteractionZoneBox; // 0x268(0x08)
	struct URBActiveSkillVisionComponent* ActiveSkillVisionComponent; // 0x270(0x08)
	struct UStaticMeshComponent* ActiveSkillWaveSphere; // 0x278(0x08)
	char ItemDefinition[0x48]; // 0x280(0x48)
	struct UMeshComponent* InWorldMeshComponent; // 0x2c8(0x08)
	struct UMeshComponent* InHandMeshComponent; // 0x2d0(0x08)
	float WaterFloatingDepth; // 0x2d8(0x04)
	char pad_2DC[0x4]; // 0x2dc(0x04)
	struct USceneComponent* SpawnPointRef; // 0x2e0(0x08)
	char pad_2E8[0x8]; // 0x2e8(0x08)
	char SpawnPointRelativeInverseTransform[0x30]; // 0x2f0(0x30)
	struct UItemAnimRef* AnimationData1P; // 0x320(0x08)
	struct UItemAnimRef* AnimationData1PDown; // 0x328(0x08)
	struct UItemAnimRef* AnimationData3P; // 0x330(0x08)
	float staminaRestoreAmount; // 0x338(0x04)
	float HealthRestoreAmount; // 0x33c(0x04)
	float TemporaryHealthRestoreAmount; // 0x340(0x04)
	float PsychosisRestoreAmount; // 0x344(0x04)
	float BatteryRestoreAmount; // 0x348(0x04)
	bool bResetActiveSkillCooldown; // 0x34c(0x01)
	char pad_34D[0x3]; // 0x34d(0x03)
	char AttributeModifier[0xd0]; // 0x350(0xd0)
	float noStaminaConsumptionDuration; // 0x420(0x04)
	float MovementSpeedBonusMultiplier; // 0x424(0x04)
	char PickupTutorialData[0x38]; // 0x428(0x38)
	bool bOverrideTutorialDefaultDuration; // 0x460(0x01)
	char pad_461[0x7]; // 0x461(0x07)
	char EquippedTutorialData[0x20]; // 0x468(0x20)
	bool bDisableHoldUseTutorial; // 0x488(0x01)
	bool bDisablesInputInTutorial; // 0x489(0x01)
	char pad_48A[0x6]; // 0x48a(0x06)
	char CustomInteractionText[0x18]; // 0x490(0x18)
	char CannotUseTwiceCustomText[0x18]; // 0x4a8(0x18)
	char NoRoomInInventoryInteractionText[0x18]; // 0x4c0(0x18)
	struct FString PickupSwitchName; // 0x4d8(0x10)
	struct URBOutlineComponent* OutlineComponent; // 0x4e8(0x08)
	char PickedUpEvent[0x10]; // 0x4f0(0x10)
	char DroppedEvent[0x10]; // 0x500(0x10)
	char DuplicatedEvent[0x10]; // 0x510(0x10)
	char OnConsumedChanged[0x10]; // 0x520(0x10)
	char OnPlayerOwnerChanged[0x10]; // 0x530(0x10)
	char OnTossDone[0x10]; // 0x540(0x10)
	struct UTexture2D* Icon; // 0x550(0x08)
	struct UTexture2D* HoldConsumeIcon; // 0x558(0x08)
	char HoldConsumeText[0x18]; // 0x560(0x18)
	char DisplayName[0x18]; // 0x578(0x18)
	bool bOverrideCategoryColor; // 0x590(0x01)
	char pad_591[0x3]; // 0x591(0x03)
	struct FLinearColor InventoryItemColor; // 0x594(0x10)
	bool bConsumeCameraLimit; // 0x5a4(0x01)
	char pad_5A5[0x3]; // 0x5a5(0x03)
	float ConsumeCameraMinYaw; // 0x5a8(0x04)
	float ConsumeCameraMaxYaw; // 0x5ac(0x04)
	float ConsumeCameraMinPitch; // 0x5b0(0x04)
	float ConsumeCameraMaxPitch; // 0x5b4(0x04)
	struct FString ServerName; // 0x5b8(0x10)
	char PawnOwner[0x88]; // 0x5c8(0x88)
	char OwnerInventorySlot[0x78]; // 0x650(0x78)
	char IsConsumedScheduled[0x70]; // 0x6c8(0x70)
	char pad_738[0x8]; // 0x738(0x08)
	char PickupTransform[0x130]; // 0x740(0x130)
	char ConsumeOutcomeProcessed[0x70]; // 0x870(0x70)
	char bDoubleDoseUsedOnce[0x70]; // 0x8e0(0x70)
	bool bIsInHand; // 0x950(0x01)
	bool bIsDuplicatedToPersistent; // 0x951(0x01)
	char pad_952[0x6]; // 0x952(0x06)
	struct ARBPawn* PickingUpPawn; // 0x958(0x08)
	struct ARBContainer* Container; // 0x960(0x08)
	char pad_968[0x8]; // 0x968(0x08)
	char ContainerPickupTransform[0x30]; // 0x970(0x30)
	bool bHasBeenPickedUp; // 0x9a0(0x01)
	char pad_9A1[0x7]; // 0x9a1(0x07)
	struct AActor* UsedOnActor; // 0x9a8(0x08)
	char pad_9B0[0x8]; // 0x9b0(0x08)
	struct ARBPawn* LastDroppedBy; // 0x9b8(0x08)
	char pad_9C0[0x10]; // 0x9c0(0x10)
};

// Class OPP.RBWorld
// Size: 0x3b10 (Inherited: 0x28)
struct URBWorld : UObject {
	char pad_28[0x8]; // 0x28(0x08)
	struct TArray<struct URBAimAssistComponent*> AimAssistComponents; // 0x30(0x10)
	struct TArray<struct ARBAISpawner*> AISpawners; // 0x40(0x10)
	struct TArray<struct UPointLightComponent*> AllDynamicLights; // 0x50(0x10)
	struct TArray<struct ALightmassImportanceVolume*> AllLightmassImportanceVolumes; // 0x60(0x10)
	struct TArray<struct ARBAmbientActivityMarker*> ambientMarkers; // 0x70(0x10)
	struct TArray<struct ARBBackgroundCharacter*> BackgroundCharacters; // 0x80(0x10)
	struct TArray<struct ARBBackgroundDoor*> BackgroundDoors; // 0x90(0x10)
	struct TArray<struct URBBoxNavMeshBlockingComponent*> BoxNavMeshBlockingComponents; // 0xa0(0x10)
	struct TArray<struct ARBDoor*> Doors; // 0xb0(0x10)
	struct TArray<struct AActor*> RandomBlockableActors; // 0xc0(0x10)
	struct TArray<struct AActor*> BlockedActors; // 0xd0(0x10)
	struct TArray<struct URBHackPanelComponent*> HackPanelComponents; // 0xe0(0x10)
	struct TArray<struct ARBHittableActor*> Hittables; // 0xf0(0x10)
	struct TArray<struct URBNPCInterestPointComponent*> InterestPoints; // 0x100(0x10)
	struct TArray<struct URBPlayerDetectionComponent*> PlayerDetectionComponents; // 0x110(0x10)
	struct TArray<struct ARBInvestigationPoint*> InvestigationPoints; // 0x120(0x10)
	struct TArray<struct ARBItemSpawningManager*> ItemSpawningManagers; // 0x130(0x10)
	struct TArray<struct URBLocalPlayerProximityComponent*> LocalPlayerProximityComponents; // 0x140(0x10)
	struct TArray<struct URBLocalPlayerVisibilityComponent*> LocalPlayerVisibilityComponents; // 0x150(0x10)
	char pad_160[0x10]; // 0x160(0x10)
	struct TArray<struct ARBMonsterCloset*> MonsterClosets; // 0x170(0x10)
	struct TArray<struct ARBNPC*> NPCs; // 0x180(0x10)
	struct TArray<struct ARBNPC*> NightHunters; // 0x190(0x10)
	struct TArray<struct URBOutlineComponent*> OutlineComponents; // 0x1a0(0x10)
	struct TArray<struct ARBPlayerCell*> PlayerCells; // 0x1b0(0x10)
	struct TArray<struct URBPropOptimizerComponent*> PropOptimizers; // 0x1c0(0x10)
	struct TArray<struct ARBPushCartSpawner*> PushCartSpawners; // 0x1d0(0x10)
	struct TArray<struct URBPuzzleRoomComponent*> PuzzleRooms; // 0x1e0(0x10)
	struct TArray<struct ARBRandomManager*> RandomManagers; // 0x1f0(0x10)
	struct TArray<struct URBActiveSkillVisionComponent*> RBActiveSkillVisionComponents; // 0x200(0x10)
	struct TArray<struct ARBBreakableObstacle*> RBBreakableObstacles; // 0x210(0x10)
	struct TArray<struct URBDamageableComponent*> RBDamageableComponents; // 0x220(0x10)
	struct TArray<struct URBHidespotComponent*> RBHidespotComponents; // 0x230(0x10)
	struct TArray<struct ARBIconMergerVolume*> RBIconMergerVolumes; // 0x240(0x10)
	struct TArray<struct ARBInteractible*> RBInteractibles; // 0x250(0x10)
	struct TArray<struct ARBLargePickup*> RBLargePickups; // 0x260(0x10)
	struct TArray<struct ARBBasePushable*> RBPushables; // 0x270(0x10)
	struct TArray<struct ARBPawn*> RBPawns; // 0x280(0x10)
	struct TArray<struct ARBPickup*> RBPickups; // 0x290(0x10)
	struct TArray<struct ARBPlayer*> RBPlayers; // 0x2a0(0x10)
	struct TArray<struct URBRandomAmbientSoundComponent*> RBRandomAmbientSounds; // 0x2b0(0x10)
	struct TArray<struct ARBPlayerRespawner*> RBRespawners; // 0x2c0(0x10)
	struct TArray<struct URBRepulsionComponent*> RepulsionComponents; // 0x2d0(0x10)
	struct TArray<struct URBRewardRoomComponent*> RewardRooms; // 0x2e0(0x10)
	struct TArray<struct UObject*> WorldPopulateInterfaceObjects; // 0x2f0(0x10)
	struct TArray<struct UObject*> WorldFullyLoadedToCallObjects; // 0x300(0x10)
	struct TArray<struct ARBRoom*> Rooms; // 0x310(0x10)
	struct TArray<struct ARBRoomGroup*> RoomGroups; // 0x320(0x10)
	struct TArray<struct ARBRoomGroup*> MissionRoomGroups; // 0x330(0x10)
	struct ARBHallucinationManager* HallucinationManager; // 0x340(0x08)
	struct TArray<struct ARBSAS*> SASList; // 0x348(0x10)
	struct ARBEvalCorridor* CurrentEvalCorridor; // 0x358(0x08)
	struct TArray<struct ARBCrouchUnderMarker*> SlideUnderMarkers; // 0x360(0x10)
	struct TArray<struct URBSoundConnectorComponent*> SoundConnectors; // 0x370(0x10)
	struct TArray<struct ARBSoundVolume*> SoundVolumes; // 0x380(0x10)
	struct TArray<struct URBSinglePlayerHelperComponent*> SinglePlayerHelperComponentList; // 0x390(0x10)
	struct TArray<struct URBEvalCorridorHelperComponent*> EvalCorridorHelperComponentList; // 0x3a0(0x10)
	struct TArray<struct URBRailForPushableComponent*> RailForPushableComponentList; // 0x3b0(0x10)
	struct TArray<struct FObstacleVariatorComponentList> ObstacleVariatorComponentLists; // 0x3c0(0x10)
	struct TArray<struct ARBSASTransitionZone*> TransitionZones; // 0x3d0(0x10)
	struct TArray<struct ARBTriggerableGate*> TriggerableGates; // 0x3e0(0x10)
	struct TArray<struct ARBNarrativeScreen*> NarrativeScreens; // 0x3f0(0x10)
	struct TArray<struct ARBNarrativeScreenChannel*> NarrativeScreenChannels; // 0x400(0x10)
	struct TArray<struct ARBLedgeMarker*> UnvalidatedLedgeMarkers; // 0x410(0x10)
	struct TArray<struct ARBVolumetricFog*> VolumetricFogs; // 0x420(0x10)
	struct TArray<struct ARBVolumetricFogAlternateDensityVolume*> FogAlternateDensityVolumes; // 0x430(0x10)
	struct TArray<struct URBWaterSimulationComponent*> WaterSimulations; // 0x440(0x10)
	struct TArray<struct ARBWaypoint*> Waypoints; // 0x450(0x10)
	struct TArray<struct ARBWaypointGroup*> WaypointGroups; // 0x460(0x10)
	struct TArray<struct FLongJumpInfo> LongJumps; // 0x470(0x10)
	struct TArray<struct ARBPushCartGoalManager*> PushCartGoalManagers; // 0x480(0x10)
	struct TArray<struct URBSinglePlayerHelperComponent*> SinglePlayerHelperComponentToProcess; // 0x490(0x10)
	struct TArray<struct URBRoomAssociationComponent*> RoomAssociationComponents; // 0x4a0(0x10)
	struct TArray<struct URBRoomConnectorComponent*> RoomConnectorComponents; // 0x4b0(0x10)
	struct TArray<struct URBObjectiveProximityComponent*> ObjectiveProximityComponents; // 0x4c0(0x10)
	struct TArray<struct ARBTrapGroup*> TrapGroups; // 0x4d0(0x10)
	char ObstacleRandomizationRuntimeData[0xc0]; // 0x4e0(0xc0)
	struct TArray<struct FTemporaryAttachmentInfo> TemporaryAttachments; // 0x5a0(0x10)
	struct TArray<struct ARBGeneratorMultiObjectiveActor*> Generators; // 0x5b0(0x10)
	struct TArray<struct ARBWaterVolume*> WaterVolumes; // 0x5c0(0x10)
	struct TArray<struct URBWaterRippleEmitter*> WaterRippleEmitters; // 0x5d0(0x10)
	struct TArray<struct URBRandomizableHelperComponent*> RandomizableHelperComponents; // 0x5e0(0x10)
	struct TArray<struct ULevel*> LevelsToPopulate; // 0x5f0(0x10)
	struct TArray<struct ULevel*> AddedLevels; // 0x600(0x10)
	struct TArray<struct FDelayedActionHandle> ReplicationCallback; // 0x610(0x10)
	char pad_620[0x6c0]; // 0x620(0x6c0)
	struct TArray<struct ARBThrowableWeapon*> ActiveThrowableWeapons; // 0xce0(0x10)
	struct TArray<struct ARBSplineFollowingActor*> SplineFollowingActors; // 0xcf0(0x10)
	struct TArray<struct URBNetworkSyncComponent*> NetworkSyncComponents; // 0xd00(0x10)
	struct ARBAnnouncer* RBAnnouncer; // 0xd10(0x08)
	struct ARBStreaming* RBStreaming; // 0xd18(0x08)
	struct ARBTaskManager* RBTaskManager; // 0xd20(0x08)
	struct ARBPlayerProgressionManager* RBPlayerProgressionManager; // 0xd28(0x08)
	struct ARBPlayerLoadoutManager* RBPlayerLoadoutManager; // 0xd30(0x08)
	struct ARBTextChatManager* RBTextChatManager; // 0xd38(0x08)
	struct ARBVariatorManager* VariatorManager; // 0xd40(0x08)
	bool bIsResettingStage; // 0xd48(0x01)
	char pad_D49[0x17]; // 0xd49(0x17)
	char OnInteractibleRegistered[0x10]; // 0xd60(0x10)
	char OnInteractibleUnregistered[0x10]; // 0xd70(0x10)
	char OnRBStreamingInitialized[0x10]; // 0xd80(0x10)
	char OnPopulateFinished[0x10]; // 0xd90(0x10)
	char OnTextChatManagerRegistered[0x10]; // 0xda0(0x10)
	char OnPawnRegistered[0x10]; // 0xdb0(0x10)
	char OnPawnUnregistered[0x10]; // 0xdc0(0x10)
	char pad_DD0[0x68]; // 0xdd0(0x68)
	struct TArray<struct ARBAISpawner*> LevelAISpawnersToPopulate; // 0xe38(0x10)
	struct TArray<struct UObject*> WorldPopulateInterfaceObjectToPopulate; // 0xe48(0x10)
	struct TArray<struct ARBContainer*> ContainersToSpawnItems; // 0xe58(0x10)
	struct TArray<struct ARBItemSpawningManager*> ItemSpawningManagersToPopulate; // 0xe68(0x10)
	struct TArray<struct URBPuzzleRoomComponent*> PuzzleRoomsToPopulate; // 0xe78(0x10)
	struct TArray<struct URBRewardRoomComponent*> RewardRoomsToPopulate; // 0xe88(0x10)
	struct TArray<struct URBRewardRoomComponent*> RewardRoomsToSetup; // 0xe98(0x10)
	struct TArray<struct ARBSASTransitionZone*> TransitionZonesToPopulate; // 0xea8(0x10)
	struct TArray<struct ARBBaseObjectiveCoordinator*> ObjCoordinatorsToPrepare; // 0xeb8(0x10)
	struct TArray<struct ARBBaseObjectiveCoordinator*> ObjCoordinatorsToPopulate; // 0xec8(0x10)
	struct TArray<struct ARBBaseObjectiveCoordinator*> RailObjCoordinatorsToPopulate; // 0xed8(0x10)
	struct TArray<struct ARBBaseObjectiveCoordinator*> PreDoorRandomizationObjCoordinatorsToPopulate; // 0xee8(0x10)
	struct TArray<struct ARBBaseObjectiveCoordinator*> ObjCoordinatorsToSetup; // 0xef8(0x10)
	struct TArray<struct URBObjectiveProximityComponent*> ObjectiveProximityComponentsToPopulate; // 0xf08(0x10)
	struct TArray<struct ARBWaypointGroup*> WaypointGroupsToPopulate; // 0xf18(0x10)
	struct TArray<struct ARBTriggerableGate*> VariatorGatesToPopulate; // 0xf28(0x10)
	struct TArray<struct URBHidespotComponent*> HidespotComponentsToPopulate; // 0xf38(0x10)
	struct TArray<struct ARBRoomGroup*> RoomGroupsToBuildCaches; // 0xf48(0x10)
	struct TArray<struct ARBRoomGroup*> MissionRoomGroupsToPopulate; // 0xf58(0x10)
	struct TArray<struct URBRewardRoomComponent*> RewardRoomsToFinalize; // 0xf68(0x10)
	char FullStageSectionData[0x2ac8]; // 0xf78(0x2ac8)
	bool bFullStageSectionDataValid; // 0x3a40(0x01)
	char pad_3A41[0x7]; // 0x3a41(0x07)
	struct TArray<struct ARBRoomGroup*> RoomGroupsToRandomizeBlocked; // 0x3a48(0x10)
	struct TArray<struct ARBRoomGroup*> RoomGroupsToRandomizeDoors; // 0x3a58(0x10)
	struct TArray<struct ARBRoomGroup*> RoomGroupsToRandomizeHidespots; // 0x3a68(0x10)
	struct TArray<struct URBRoomAssociationComponent*> RoomAssociationComponentsToPopulate; // 0x3a78(0x10)
	struct TArray<struct URBRoomConnectorComponent*> RoomConnectorComponentsToPopulate; // 0x3a88(0x10)
	struct TArray<struct ARBRoom*> RoomsToBuildCaches; // 0x3a98(0x10)
	struct TArray<struct ARBRandomManager*> RandomManagersToUpdate; // 0x3aa8(0x10)
	struct TArray<struct AActor*> NavmeshActorsToRegister; // 0x3ab8(0x10)
	char pad_3AC8[0x8]; // 0x3ac8(0x08)
	struct TArray<struct AActor*> ActiveSkillVisionActors; // 0x3ad0(0x10)
	struct TArray<struct AActor*> ActorsToClean; // 0x3ae0(0x10)
	struct TArray<struct USkinnedMeshComponent*> SkinnedMeshComponents; // 0x3af0(0x10)
	char pad_3B00[0x10]; // 0x3b00(0x10)

	struct URBWaterSimulationComponent* GetRBWaterSimulationComponent(); // Function OPP.RBWorld.GetRBWaterSimulationComponent // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38aac
	struct TArray<struct ARBPlayerRespawner*> GetRBRespawners(); // Function OPP.RBWorld.GetRBRespawners // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38a38
	struct TArray<struct ARBPlayer*> GetRBPlayers(); // Function OPP.RBWorld.GetRBPlayers // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38a1c
	struct TArray<struct ARBPickup*> GetRBPickups(); // Function OPP.RBWorld.GetRBPickups // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38a00
	struct TArray<struct ARBPawn*> GetRBPawns(); // Function OPP.RBWorld.GetRBPawns // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e389e4
	struct TArray<struct ARBLargePickup*> GetRBLargePickups(); // Function OPP.RBWorld.GetRBLargePickups // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e389c8
	struct TArray<struct ARBInteractible*> GetRBInteractibles(); // Function OPP.RBWorld.GetRBInteractibles // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e389ac
	struct TArray<struct ARBBreakableObstacle*> GetRBBreakableObstacles(); // Function OPP.RBWorld.GetRBBreakableObstacles // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38938
	struct TArray<struct ARBNPC*> GetNPCs(); // Function OPP.RBWorld.GetNPCs // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e3891c
	struct TArray<struct ARBMonsterCloset*> GetMonsterClosets(); // Function OPP.RBWorld.GetMonsterClosets // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e388a8
	struct TArray<struct ARBDoor*> GetDoors(); // Function OPP.RBWorld.GetDoors // (Final|Native|Public|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e38844
	float EstimateFogDensity(struct FVector& Location); // Function OPP.RBWorld.EstimateFogDensity // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x1e387b0
	void BP_RegisterActorToClean(struct AActor* Actor); // Function OPP.RBWorld.BP_RegisterActorToClean // (Final|Native|Public|BlueprintCallable) // @ game+0x1e3871c
};

// Class OPP.RBGameInstance
// Size: 0x3f0 (Inherited: 0x1a8)
struct URBGameInstance : UGameInstance {
	char pad_1A8[0x8]; // 0x1a8(0x08)
	struct ARBSpectatorPawn* SpectatorPawnClass; // 0x1b0(0x08)
	struct AHUD* HUDClass; // 0x1b8(0x08)
	struct ARBBot* BotClass; // 0x1c0(0x08)
	struct URBGlobalAIConfig* DefaultSpecialistsConfig; // 0x1c8(0x08)
	struct URBNPCConfigRedirectors* ConfigRedirectors; // 0x1d0(0x08)
	struct AActor* NarratorClass; // 0x1d8(0x08)
	struct URBLocalProfile* CurrentUserLocalProfile; // 0x1e0(0x08)
	struct FString CurrentUserLocalProfileSlotName; // 0x1e8(0x10)
	int32_t CurrentUserLocalProfileUserIndex; // 0x1f8(0x04)
	char pad_1FC[0x4]; // 0x1fc(0x04)
	struct URBVoiceChatManager* VoiceChatManager; // 0x200(0x08)
	struct URBAudioManager* AudioManager; // 0x208(0x08)
	struct TArray<struct URBPlayerProgressionData*> PlayerProgressionDataConfigs; // 0x210(0x10)
	struct AActor* Narrator; // 0x220(0x08)
	struct URBVOSoundComponent* NarratorSoundComponent; // 0x228(0x08)
	struct URBMenuManager* MenuManager; // 0x230(0x08)
	struct URBAIManager* AIManager; // 0x238(0x08)
	struct URBSpatialReasoning* SpatialReasoning; // 0x240(0x08)
	struct URBAnimManager* AnimManager; // 0x248(0x08)
	struct URBFXManager* FXManager; // 0x250(0x08)
	struct URBObjectiveManager* ObjectiveManager; // 0x258(0x08)
	struct URBGameplayAttributeManager* AttributeManager; // 0x260(0x08)
	struct URBPawnCustomizationManager* PawnCustomizationManager; // 0x268(0x08)
	struct URBWorld* RBWorld; // 0x270(0x08)
	struct ARBPostProcessUpdateManager* PostProcessUpdateManager; // 0x278(0x08)
	struct URBTutorialManager* RBTutorialManager; // 0x280(0x08)
	struct URBStatsManager* RBStatsManager; // 0x288(0x08)
	struct URBAchievementManager* RBAchievementManager; // 0x290(0x08)
	struct URBGameStructureConfig* GameStructureConfig; // 0x298(0x08)
	struct URBGlobalUIConfig* GlobalUIConfig; // 0x2a0(0x08)
	struct URBGlobalAudioConfig* GlobalAudioConfig; // 0x2a8(0x08)
	struct URBGlobalAnimConfig* GlobalAnimConfig; // 0x2b0(0x08)
	struct URBPlayerStatsConfig* PlayerStatsConfig; // 0x2b8(0x08)
	struct URBAchievementsConfig* AchievementsConfig; // 0x2c0(0x08)
	struct URBScoringConfig* ScoringConfig; // 0x2c8(0x08)
	struct URBTasksConfig* TasksConfig; // 0x2d0(0x08)
	struct URBNPCArchetypeConfig* NPCArchetypesConfig; // 0x2d8(0x08)
	struct URBPlayerCustomizationConfig* PlayerCustomizationConfig; // 0x2e0(0x08)
	struct URBPlayerCellCustomizationConfig* PlayerCellCustomizationConfig; // 0x2e8(0x08)
	struct URBCollectibleDocumentsConfig* CollectibleDocumentsConfig; // 0x2f0(0x08)
	struct URBPlayerLoadoutConfig* PlayerLoadoutConfig; // 0x2f8(0x08)
	struct URBPlayerGameSessionManager* PlayerGameSessionManager; // 0x300(0x08)
	struct URBChunkInstallManager* ChunkInstallManager; // 0x308(0x08)
	char OnPlayerJoinedGame[0x10]; // 0x310(0x10)
	char OnPlayerLeftGame[0x10]; // 0x320(0x10)
	char OnSaveGameWritten[0x10]; // 0x330(0x10)
	char OnSaveGameLoaded[0x10]; // 0x340(0x10)
	char pad_350[0x90]; // 0x350(0x90)
	struct TArray<struct FCachedRuntimeCustomizationResources> CachedCustomization; // 0x3e0(0x10)

	void AsyncWriteProfileDone(struct FString SlotName, int32_t UserIndex, bool bSuccess); // Function OPP.RBGameInstance.AsyncWriteProfileDone // (Final|Native|Public) // @ game+0x1d60f94
	void AsyncLoadProfileDone(struct FString SlotName, int32_t UserIndex, struct USaveGame* SaveGame); // Function OPP.RBGameInstance.AsyncLoadProfileDone // (Final|Native|Public) // @ game+0x1d60e7c
};

struct ULevel {
	char pad_28[0x98]; // 0x28(0x90)
	TArray<class AActor*> NearActors;
};

struct AGameStateBase {
	char pad_00[0x18];
	struct TArray<struct APlayerState*> PlayerArray; // 0x260(0x10)
	bool bReplicatedHasBegunPlay; // 0x270(0x01)
	char pad_271[0x17]; // 0x271(0x17)
};

struct UWorld : UObject {
	char pad_28[0x8]; // 0x28(0x08)
	struct ULevel* PersistentLevel; // 0x30(0x08)
	struct UNetDriver* NetDriver; // 0x38(0x08)
	struct ULineBatchComponent* LineBatcher; // 0x40(0x08)
	struct ULineBatchComponent* PersistentLineBatcher; // 0x48(0x08)
	struct ULineBatchComponent* ForegroundLineBatcher; // 0x50(0x08)
	struct AGameNetworkManager* NetworkManager; // 0x58(0x08)
	struct UPhysicsCollisionHandler* PhysicsCollisionHandler; // 0x60(0x08)
	struct TArray<struct UObject*> ExtraReferencedObjects; // 0x68(0x10)
	struct TArray<struct UObject*> PerModuleDataObjects; // 0x78(0x10)
	struct TArray<struct ULevelStreaming*> StreamingLevels; // 0x88(0x10)
	char StreamingLevelsToConsider[0x28]; // 0x98(0x28)
	char StreamingLevelsPrefix[0x10]; // 0xc0(0x10)
	struct ULevel* CurrentLevelPendingVisibility; // 0xd0(0x08)
	struct ULevel* CurrentLevelPendingInvisibility; // 0xd8(0x08)
	struct ULevel* CurrentLevelPendingReregister; // 0xe0(0x08)
	struct UDemoNetDriver* DemoNetDriver; // 0xe8(0x08)
	struct AParticleEventManager* MyParticleEventManager; // 0xf0(0x08)
	struct APhysicsVolume* DefaultPhysicsVolume; // 0xf8(0x08)
	char pad_100[0x16]; // 0x100(0x16)
	char pad_116_0 : 2; // 0x116(0x01)
	char bAreConstraintsDirty : 1; // 0x116(0x01)
	char pad_116_3 : 5; // 0x116(0x01)
	char pad_117[0x1]; // 0x117(0x01)
	struct UNavigationSystemBase* NavigationSystem; // 0x118(0x08)
	struct AGameModeBase* AuthorityGameMode; // 0x120(0x08)
	struct AGameStateBase* GameState; // 0x128(0x08)
	struct UAISystemBase* AISystem; // 0x130(0x08)
	struct UAvoidanceManager* AvoidanceManager; // 0x138(0x08)
	struct TArray<struct ULevel*> Levels; // 0x140(0x10)
	struct TArray<struct FLevelCollection> LevelCollections; // 0x150(0x10)
	char pad_160[0x28]; // 0x160(0x28)
	struct UGameInstance* OwningGameInstance; // 0x188(0x08)
	struct TArray<struct UMaterialParameterCollectionInstance*> ParameterCollectionInstances; // 0x190(0x10)
	struct UCanvas* CanvasForRenderingToTarget; // 0x1a0(0x08)
	struct UCanvas* CanvasForDrawMaterialToRenderTarget; // 0x1a8(0x08)
	char pad_1B0[0x50]; // 0x1b0(0x50)
	struct UPhysicsFieldComponent* PhysicsField; // 0x200(0x08)
	char ComponentsThatNeedPreEndOfFrameSync[0x50]; // 0x208(0x50)
	struct TArray<struct UActorComponent*> ComponentsThatNeedEndOfFrameUpdate; // 0x258(0x10)
	struct TArray<struct UActorComponent*> ComponentsThatNeedEndOfFrameUpdate_OnGameThread; // 0x268(0x10)
	char pad_278[0x378]; // 0x278(0x378)
	struct UWorldComposition* WorldComposition; // 0x5f0(0x08)
	char pad_5F8[0x90]; // 0x5f8(0x90)
	char PSCPool[0x58]; // 0x688(0x58)
	char pad_6E0[0xc8]; // 0x6e0(0xc8)

	struct AWorldSettings* K2_GetWorldSettings(); // Function Engine.World.K2_GetWorldSettings // (Final|Native|Public|BlueprintCallable) // @ game+0x35fb64c
	void HandleTimelineScrubbed(); // Function Engine.World.HandleTimelineScrubbed // (Final|Native|Public) // @ game+0x35fb638
};

struct UCanvas : UObject {
	float OrgX; // 0x28(0x04)
	float OrgY; // 0x2c(0x04)
	float ClipX; // 0x30(0x04)
	float ClipY; // 0x34(0x04)
	int DrawColor; // 0x38(0x04)
	char bCenterX : 1; // 0x3c(0x01)
	char bCenterY : 1; // 0x3c(0x01)
	char bNoSmooth : 1; // 0x3c(0x01)
	char pad_3C_3 : 5; // 0x3c(0x01)
	char pad_3D[0x3]; // 0x3d(0x03)
	int32_t SizeX; // 0x40(0x04)
	int32_t SizeY; // 0x44(0x04)
	char pad_48[0x8]; // 0x48(0x08)
	char ColorModulate[0x10]; // 0x50(0x10)
	struct UTexture2D* DefaultTexture; // 0x60(0x08)
	struct UTexture2D* GradientTexture0; // 0x68(0x08)
	struct UReporterGraph* ReporterGraph; // 0x70(0x08)
	char pad_78[0x258]; // 0x78(0x258)

	struct FVector2D K2_TextSize(struct UFont* RenderFont, struct FString RenderText, struct FVector2D Scale); // Function Engine.Canvas.K2_TextSize // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c20a8
	struct FVector2D K2_StrLen(struct UFont* RenderFont, struct FString RenderText); // Function Engine.Canvas.K2_StrLen // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c1fa8
	struct FVector K2_Project(struct FVector WorldLocation); // Function Engine.Canvas.K2_Project // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c1ef4
	void K2_DrawTriangle(struct UTexture* RenderTexture, struct TArray<struct FCanvasUVTri> Triangles); // Function Engine.Canvas.K2_DrawTriangle // (Final|Native|Public|BlueprintCallable) // @ game+0x34c1d8c
	void K2_DrawTexture(struct UTexture* RenderTexture, struct FVector2D ScreenPosition, struct FVector2D ScreenSize, struct FVector2D CoordinatePosition, struct FVector2D CoordinateSize, struct FLinearColor RenderColor, enum class EBlendMode BlendMode, float Rotation, struct FVector2D PivotPoint); // Function Engine.Canvas.K2_DrawTexture // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c1aec
	void K2_DrawText(struct UObject* RenderFont, struct FString RenderText, struct FVector2D ScreenPosition, struct FVector2D Scale, struct FLinearColor RenderColor, float Kerning, struct FLinearColor ShadowColor, struct FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, struct FLinearColor OutlineColor); // Function Engine.Canvas.K2_DrawText // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c1668
	void K2_DrawPolygon(struct UTexture* RenderTexture, struct FVector2D ScreenPosition, struct FVector2D Radius, int32_t NumberOfSides, struct FLinearColor RenderColor); // Function Engine.Canvas.K2_DrawPolygon // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c1460
	void K2_DrawMaterialTriangle(struct UMaterialInterface* RenderMaterial, struct TArray<struct FCanvasUVTri> Triangles); // Function Engine.Canvas.K2_DrawMaterialTriangle // (Final|Native|Public|BlueprintCallable) // @ game+0x34c12fc
	void K2_DrawMaterial(struct UMaterialInterface* RenderMaterial, struct FVector2D ScreenPosition, struct FVector2D ScreenSize, struct FVector2D CoordinatePosition, struct FVector2D CoordinateSize, float Rotation, struct FVector2D PivotPoint); // Function Engine.Canvas.K2_DrawMaterial // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c0fc8
	void K2_DrawLine(struct FVector2D ScreenPositionA, struct FVector2D ScreenPositionB, float Thickness, struct FLinearColor RenderColor); // Function Engine.Canvas.K2_DrawLine // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c0e84
	void K2_DrawBox(struct FVector2D ScreenPosition, struct FVector2D ScreenSize, float Thickness, struct FLinearColor RenderColor); // Function Engine.Canvas.K2_DrawBox // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c0d40
	void K2_DrawBorder(struct UTexture* BorderTexture, struct UTexture* BackgroundTexture, struct UTexture* LeftBorderTexture, struct UTexture* RightBorderTexture, struct UTexture* TopBorderTexture, struct UTexture* BottomBorderTexture, struct FVector2D ScreenPosition, struct FVector2D ScreenSize, struct FVector2D CoordinatePosition, struct FVector2D CoordinateSize, struct FLinearColor RenderColor, struct FVector2D BorderScale, struct FVector2D BackgroundScale, float Rotation, struct FVector2D PivotPoint, struct FVector2D CornerSize); // Function Engine.Canvas.K2_DrawBorder // (Final|Native|Public|HasDefaults|BlueprintCallable) // @ game+0x34c06c4
	void K2_Deproject(struct FVector2D ScreenPosition, struct FVector& WorldOrigin, struct FVector& WorldDirection); // Function Engine.Canvas.K2_Deproject // (Final|Native|Public|HasOutParms|HasDefaults|BlueprintCallable) // @ game+0x34c05ac
};
