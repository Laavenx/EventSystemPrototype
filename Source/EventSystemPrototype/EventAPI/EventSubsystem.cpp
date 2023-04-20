// Fill out your copyright notice in the Description page of Project Settings.


#include "EventSubsystem.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h" 
#include "Interfaces/ITargetDevice.h"

void UEventSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	UE_LOG(LogTemp, Warning, TEXT("Subsystem initialized"));
}

void UEventSubsystem::SubmitEvent(FMyStruct Inputs)
{
	switch (Inputs.EventType)
	{
		case EEventType::Unit_Move:
			OnUnitMarch.Broadcast(Inputs.Sound ,Inputs.Target);
			break;
		case EEventType::Play_March_Sound:
			OnUnitOrder.Broadcast(Inputs.Sound);
			break;
	}
}
