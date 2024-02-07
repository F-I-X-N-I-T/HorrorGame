// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights/FlashingLight.h"

// Sets default values
AFlashingLight::AFlashingLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AFlashingLight::BeginPlay()
{
	Super::BeginPlay();

	PointLight->Intensity;

	//float InitIntensity = PointLight->Intensity;

	//timeline
	Timeline.PlayFromStart();
	
	FOnTimelineFloat TimelineProgress;
	TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
	Timeline.SetTimelineLength(1.f);
	Timeline.SetLooping(true);
	Timeline.AddInterpFloat(Curve, TimelineProgress);

	
	//float Progress = Timeline.GetPlaybackPosition();
	//float ProgressTimeLineAndCurve = Curve->GetFloatValue(Progress);

	//float NewIntensity = (Progress * ProgressTimeLineAndCurve);
	
	//PointLight->SetIntensity(NewIntensity);
	
}

// Called every frame
void AFlashingLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
	float Progress = Timeline.GetPlaybackPosition();
	UE_LOG(LogTemp, Warning, TEXT("Valor actual del nuevo track float: %f"), Progress);
	
    float ProgressTimeLineAndCurve = Curve->GetFloatValue(Progress);
    
    float NewIntensity = (Progress * ProgressTimeLineAndCurve);
    	
    PointLight->SetIntensity(NewIntensity);

}

