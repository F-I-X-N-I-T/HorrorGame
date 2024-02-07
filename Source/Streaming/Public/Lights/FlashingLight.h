// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "FlashingLight.generated.h"

UCLASS()
class STREAMING_API AFlashingLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashingLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimeline Timeline;

	UPROPERTY(EditAnywhere, Category = "Light")
	UCurveFloat* Curve;

private:

	UPROPERTY()
	UPointLightComponent* PointLight;

};
