// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Number.h"
#include "Engine.h"

// Sets default values
ANumber::ANumber()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Number = CreateDefaultSubobject<UBoxComponent>(TEXT("Door"));
	Number->bGenerateOverlapEvents = true;
	Number->OnComponentBeginOverlap.AddDynamic(this, &ANumber::TriggerEnter);
	RootComponent = Number;
	SMNumber = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	SMNumber->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ANumber::BeginPlay()
{
	Super::BeginPlay();

}

void ANumber::GetCode(AActor *I)
{
	Button = Cast<AButtonA>(I);
}

// Called every frame
void ANumber::Tick(float DeltaTime)
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

void ANumber::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA(AActor::StaticClass()) && c == 0)
	{
		
		GetCode(OtherActor);
		c++;
	}
}
