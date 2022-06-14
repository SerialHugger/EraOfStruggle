// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterPawn.h"
#include "../Debug.h"

// Sets default values
AMasterPawn::AMasterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AMasterPawn::UpdatePawn(UMasterPawnDataAsset* NewDataAsset)
{
	UDebug::Log("Update Pawn");
}

// Called when the game starts or when spawned
void AMasterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void AMasterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

