// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Wall.h"
#include "Engine.h"

// Sets default values
AWall::AWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Wall = CreateDefaultSubobject<UBoxComponent>(TEXT("Door"));
	Wall->bGenerateOverlapEvents = true;
	Wall->OnComponentBeginOverlap.AddDynamic(this, &AWall::TriggerEnter);
	RootComponent = Wall;
	SMWall = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	SMWall->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();

}

void AWall::GetCode(AActor *I)
{
	Button = Cast<AButtonA>(I);
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	if (Button != NULL)
	{

		if (Button->Click == 2)
		{

			if (Location.X < -1310.0f)
			{
				Location.X += 2.0f;
				SetActorLocation(Location);
			}
		}
	}
}

void AWall::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA(AActor::StaticClass()) && c == 0)
	{
		GetCode(OtherActor);
		c++;
	}
}
