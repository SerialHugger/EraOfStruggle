// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MasterPawnDataAsset.generated.h"

class USkeletalMeshComponent;

UCLASS()
class ERAOFSTRUGGLE_API UMasterPawnDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	// Default health is 100, upgrades with each pawn tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* PawnBaseSkeletalMesh;

	// Default health is 100, upgrades with each pawn tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth = 100.f;

	// Default Damage is 20, upgrades with each pawn tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Strength = 20.f;

	// Default Damage is 20, upgrades with each pawn tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed = 20.f;

	// Default Damage is 20, upgrades with each pawn tier
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Range = 20.f;



};

