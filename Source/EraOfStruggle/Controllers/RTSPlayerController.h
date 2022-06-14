// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RTSPlayerController.generated.h"

UCLASS()
class ERAOFSTRUGGLE_API ARTSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	// ------------- Methods ------------- \\

	// Constructor
	ARTSPlayerController();

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
		FVector ControllerForwardVector();

	UFUNCTION(BlueprintCallable)
		FVector ControllerRightVector();

	// ----------- Variables ------------ \\



protected:

	// ------------- Methods ------------- \\

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// ----------- Variables ------------ \\

	FInputModeGameAndUI InputMode;

};
