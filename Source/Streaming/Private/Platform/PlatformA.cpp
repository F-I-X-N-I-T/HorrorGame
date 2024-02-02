// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/PlatformA.h"


// Sets default values
APlatformA::APlatformA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformA::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlatformA::MovePlatform(float DeltaTime)
{
	NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    
	NewLocation += MovementDirection * (DeltaHeight * Displacement);
    	
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

	AddActorLocalRotation(ObjectRotation * DeltaTime);
}



// Called every frame
void APlatformA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
