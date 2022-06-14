// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Debug.generated.h"

/**
 * 
 */
UCLASS()
class ERAOFSTRUGGLE_API UDebug : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Strings with values
	static void Log(const FString& debugMessage);
	static void Log(float duration_, const FString& debugMessage);
	static void Log(const FString& debugMessage, const FName& value_, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const float value, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const int32 value, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const bool value, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const FVector value, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const FRotator value, float duration_ = 2.0f);
	static void Log(const FString& debugMessage, const FQuat value, float duration_ = 2.0f);
	static void Error(const FString& debugMessage, float duration_ = 20.0f);

	// Draw debugs
	static void DrawPoint(UWorld* world_, FVector pos_, float lifteTime_ = -1.0f, float size_ = 15.0f, FColor color_ = FColor::Red);
	static void DrawLine(UWorld* world_, FVector startPos_, FVector endPos_, float lifteTime_ = -1.0f, FColor color_ = FColor::Green);
	static void DrawSphere(UWorld* world_, FVector pos_, float lifteTime_ = -1.0f, float radius_ = 20.0f, FColor color_ = FColor::Blue);
	static void DrawCylinder(UWorld* world_, FVector startPos_, FVector endPos_, float lifteTime_ = -1.0f, float radius_ = 5.0f, FColor color_ = FColor::Blue);
	static void DrawArrow(UWorld* world_, FVector startPos_, FVector endPos_, float lifteTime_ = -1.0f, float thickness_ = 2.0f, FColor color_ = FColor::Blue);
	static void DrawCapsule(UWorld* world_, FVector pos_, FRotator rot_, float radius_, float halfHeight, float lifteTime_ = -1.0f, FColor color_ = FColor::Blue);

};
