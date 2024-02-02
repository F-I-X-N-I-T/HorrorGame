// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformA.generated.h"

UCLASS()
class STREAMING_API APlatformA : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformA();

	// Moving platform variables
	
	UPROPERTY(EditAnywhere)
	float Displacement;

	UPROPERTY(EditAnywhere)
	FVector MovementDirection;

	UPROPERTY(EditAnywhere)
	FRotator ObjectRotation;

	UFUNCTION(BlueprintCallable)
	void MovePlatform(float DeltaTime);

	FVector NewLocation;
	
	float RunningTime;

	// End Moving platform variables
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
