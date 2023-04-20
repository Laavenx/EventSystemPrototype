// Fill out your copyright notice in the Description page of Project Settings.


#include "Manequin.h"


// Sets default values
AManequin::AManequin()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AManequin::BeginPlay()
{
	Super::BeginPlay();
	
}

void AManequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), 20.f, 12, FColor::Red, false, -1.f, 0.f, 0.5f);
}

void AManequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

