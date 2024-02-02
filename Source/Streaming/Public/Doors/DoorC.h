// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorC.generated.h"


UCLASS()
class STREAMING_API ADoorC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorC();

	UFUNCTION(BlueprintCallable)
	void InteractWithTheDoor(bool bIsOpenDoor);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Door")
	bool IsDoorClosed = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Timeline
	FTimeline Timeline;
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	UPROPERTY(EditAnywhere)
	float DoorRotationAngle = 90.f;

	UFUNCTION()
	void OpenDoor(float Value); //Bind

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Door;
};
