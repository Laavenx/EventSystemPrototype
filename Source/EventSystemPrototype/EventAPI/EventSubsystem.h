// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EventSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnitMarch, USoundBase*, Sound, AActor*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitOrder, USoundBase*, Sound);

UENUM()
enum class EEventType: uint8
{
	Unit_Move,
	Play_March_Sound,
};

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()

	EEventType EventType = EEventType::Unit_Move;
	USoundBase* Sound;
	AActor* Target = nullptr;
};

UCLASS()
class EVENTSYSTEMPROTOTYPE_API UEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(BlueprintAssignable)
	FOnUnitMarch OnUnitMarch;

	UPROPERTY(BlueprintAssignable)
	FOnUnitOrder OnUnitOrder;

	UFUNCTION(BlueprintCallable)
	void SubmitEvent(FMyStruct Inputs);
};
