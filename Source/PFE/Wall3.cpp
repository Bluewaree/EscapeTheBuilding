// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Wall3.h"
#include "Engine.h"

// Sets default values
AWall3::AWall3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Wall = CreateDefaultSubobject<UBoxComponent>(TEXT("Wall"));
	Wall->bGenerateOverlapEvents = true;
	Wall->OnComponentBeginOverlap.AddDynamic(this, &AWall3::TriggerEnter);
	RootComponent = Wall;
	SMWall = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SMWall->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AWall3::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWall3::GetButton(AActor *Button)
{
	bButton = Cast<AButtonB>(Button);
}

// Called every frame
void AWall3::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector Location = GetActorLocation();

	if (bButton != NULL)
	{
		if (bButton->Active)
		{
			while (Location.X < -670.f)
			{
				Location.X += 2.f;
				SetActorLocation(Location);
			}
		}
	}
}

void AWall3::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (c == 0)
	{
		GetButton(OtherActor);
		c++;
	}
}