// Fill out your copyright notice in the Description page of Project Settings.

#include "Doors/DoorPassword.h"
#include "Components/TimelineComponent.h"

// Sets default values
ADoorPassword::ADoorPassword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);

}

void ADoorPassword::InteractDoorPassword(bool bIsOpenDoorPassword)
{
	if (IsDoorClosedPassword)
	{
		TimelinePassword.PlayFromStart();
	}
	else
	{
		TimelinePassword.ReverseFromEnd();
	}
	IsDoorClosedPassword = !IsDoorClosedPassword;
}

// Called when the game starts or when spawned
void ADoorPassword::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorPassword::OpenDoorPassword);
		TimelinePassword.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

void ADoorPassword::OpenDoorPassword(float Value)
{
	FRotator RotDoorPass = FRotator(0.f, DoorRotationAngle * Value, 0.f);

	Door->SetRelativeRotation(RotDoorPass);
}

// Called every frame
void ADoorPassword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimelinePassword.TickTimeline(DeltaTime);
}

