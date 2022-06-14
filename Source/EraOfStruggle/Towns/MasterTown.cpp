// Fill out your copyright notice in the Description page of Project Settings.

#include "MasterTown.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "../Debug.h"
#include "../DataAssets/MasterTownDataAsset.h"

// Sets default values
AMasterTown::AMasterTown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PlaceHolderRootSceneComp = CreateDefaultSubobject<USceneComponent>("Root Scene Component");
	RootComponent = PlaceHolderRootSceneComp;

	TownBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Town Base Mesh");
	TownBaseMesh->SetupAttachment(RootComponent);

	TroopSpawnPoint = CreateDefaultSubobject<UArrowComponent>("Troop Spawn Point");
	TroopSpawnPoint->SetupAttachment(RootComponent);

	TownCollision = CreateDefaultSubobject<UBoxComponent>("Town Collision");
	TownCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMasterTown::BeginPlay()
{
	Super::BeginPlay();

	UpdateBase(TownDataAsset);

	SpawnPawn(0);
	SpawnPawn(1);
	SpawnPawn(2);


}

void AMasterTown::SpawnPawn(int32 PawnID)
{
	UDebug::Log("Spawn Pawn with ID: ", PawnID, 5.f);
}

// Called every frame
void AMasterTown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMasterTown::UpdateBase(UMasterTownDataAsset* NewDataAsset)
{
	if (NewDataAsset != nullptr)
	{
		TownDataAsset = NewDataAsset;
		UDebug::Log(5.f, "UpdateDataAsset");
	}
}
