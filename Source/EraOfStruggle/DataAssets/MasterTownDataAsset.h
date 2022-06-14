// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MasterTownDataAsset.generated.h"

// Alien Classes
class AMasterPawn;
class UStaticMeshComponent;
class UMasterPawnDataAsset;

UCLASS()
class ERAOFSTRUGGLE_API UMasterTownDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	// ----------- Variables ------------ \\

	// Mesh of the town
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* TownBaseMesh;

	// Default health is 500, upgrades with each town tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth = 500.f;

	// 3 Assets for 3 troop Melee?, Range, Mounted
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UMasterPawnDataAsset*> TroopAssetList;

	// Special Ability Changes with each town tier
	//todo
};
