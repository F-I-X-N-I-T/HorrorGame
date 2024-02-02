// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors/DoorC.h"


// Sets default values
ADoorC::ADoorC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);
}

void ADoorC::InteractWithTheDoor(bool bIsOpenDoor)
{
	if (IsDoorClosed)
	{
		Timeline.PlayFromStart();
	}
	else
	{
		Timeline.ReverseFromEnd();
	}
	IsDoorClosed = !IsDoorClosed;
}

// Called when the game starts or when spawned
void ADoorC::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorC::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

void ADoorC::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f, DoorRotationAngle * Value, 0.f);

	Door->SetRelativeRotation(Rot);
}

// Called every frame
void ADoorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
}

