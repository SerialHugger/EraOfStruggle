// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterTown.generated.h"

// Alien Classes
class UStaticMeshComponent;
class UMasterTownDataAsset;
class UArrowComponent;
class USceneComponent;
class UBoxComponent; 
class AMasterPawn;

UCLASS()
class ERAOFSTRUGGLE_API AMasterTown : public AActor
{
	GENERATED_BODY()
	
public:	
	// ----------- Components ----------- \\

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* PlaceHolderRootSceneComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UArrowComponent* TroopSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* TownBaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UBoxComponent* TownCollision;

	// ------------- Methods ------------- \\
	
	UFUNCTION(BlueprintCallable)
		void UpdateBase(UMasterTownDataAsset* NewDataAsset);

	// Sets default values for this actor's properties
	AMasterTown();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ----------- Variables ------------ \\
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Town Properties")
		int32 TownTeamID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMasterTownDataAsset* TownDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AMasterPawn> SpawnablePawnClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CurrentHealth = 500.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 0 for melee, 1 for range, 2 for mounted
	UFUNCTION(BlueprintCallable)
		void SpawnPawn(int32 PawnID); 


};
