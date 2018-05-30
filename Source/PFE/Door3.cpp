// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Door3.h"
#include "Engine.h"

// Sets default values
ADoor3::ADoor3()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UBoxComponent>(TEXT("Door"));
	Door->bGenerateOverlapEvents = true;
	Door->OnComponentBeginOverlap.AddDynamic(this, &ADoor3::TriggerEnter);
	RootComponent = Door;
	SMDoor = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	SMDoor->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ADoor3::BeginPlay()
{
	Super::BeginPlay();

}

void ADoor3::GetCode(AActor *I)
{
	Code = Cast<ACode3>(I);
}

// Called every frame
void ADoor3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	if (Code != NULL)
	{

		if (Code->Access)
		{

			if (Location.Y > -880.f)
			{
				Location.Y -= 2.0f;
				SetActorLocation(Location);
			}
		}
	}
}

void ADoor3::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA(AActor::StaticClass()) && c == 0)
	{
		GetCode(OtherActor);
		c++;
	}
}
