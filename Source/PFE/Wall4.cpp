// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Wall4.h"


// Sets default values
AWall4::AWall4()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Wall = CreateDefaultSubobject<UBoxComponent>(TEXT("Wall"));
	Wall->bGenerateOverlapEvents = true;
	Wall->OnComponentBeginOverlap.AddDynamic(this, &AWall4::TriggerEnter);
	RootComponent = Wall;
	SMWall = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SMWall->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AWall4::BeginPlay()
{
	Super::BeginPlay();

}

void AWall4::GetButton(AActor *Button)
{
	bButton = Cast<AButtonC>(Button);
}

// Called every frame
void AWall4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();

	if (bButton != NULL)
	{
		if (bButton->Active)
		{
			while (Location.X < -650.f)
			{
				Location.X += 2.f;
				SetActorLocation(Location);
			}
		}
	}
}

void AWall4::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (c == 0)
	{
		GetButton(OtherActor);
		c++;
	}
}