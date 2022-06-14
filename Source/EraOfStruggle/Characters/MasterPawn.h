// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MasterPawn.generated.h"

class UMasterPawnDataAsset;

UCLASS()
class ERAOFSTRUGGLE_API AMasterPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// ----------- Components ----------- \\
	
	// Sets default values for this pawn's properties
	AMasterPawn();

	// ------------- Methods ------------- \\
		
	UFUNCTION(BlueprintCallable)
		void UpdatePawn(UMasterPawnDataAsset* NewDataAsset);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ----------- Variables ------------ \\

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMasterPawnDataAsset* PawnDataAsset;

protected:
	// ------------- Methods ------------- \\
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ----------- Variables ------------ \\

};
