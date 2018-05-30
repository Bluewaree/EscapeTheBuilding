// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Door7.h"
#include "Engine.h"

// Sets default values
ADoor7::ADoor7()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UBoxComponent>(TEXT("Door"));
	Door->bGenerateOverlapEvents = true;
	Door->OnComponentBeginOverlap.AddDynamic(this, &ADoor7::TriggerEnter);
	RootComponent = Door;
	SMDoor = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	SMDoor->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ADoor7::BeginPlay()
{
	Super::BeginPlay();

}

void ADoor7::GetCode(AActor *I)
{
	Code = Cast<ACode7>(I);
}

// Called every frame
void ADoor7::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	if (Code != NULL)
	{

		if (Code->Access)
		{

			if (Location.Y < -1270)
			{
				Location.Y += 2.0f;
				SetActorLocation(Location);
			}
		}
	}
}

void ADoor7::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA(AActor::StaticClass()) && c == 0)
	{
		GetCode(OtherActor);
		c++;
	}
}
