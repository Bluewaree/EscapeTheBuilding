// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "Code7.h"


// Sets default values
ACode7::ACode7()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TCode = CreateDefaultSubobject<UBoxComponent>(TEXT("Code"));
	TCode->bGenerateOverlapEvents = true;
	TCode->OnComponentBeginOverlap.AddDynamic(this, &ACode7::TriggerEnter);
	TCode->OnComponentEndOverlap.AddDynamic(this, &ACode7::TriggerExit);
	RootComponent = TCode;
	STCode = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	STCode->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ACode7::BeginPlay()
{
	Super::BeginPlay();

}

void ACode7::GetPlayer(AActor * Player)
{
	bPlayer = Cast<AMyPlayer>(Player);
}

void ACode7::SetCode()
{
	if (bPlayer->ready && bItem)
	{
		if (bPlayer->number == "71")
		{
			GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("Access Granted %s"), *bPlayer->number));
			Access = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, FString::Printf(TEXT("Access Denied %s"), *bPlayer->number));
		}
	}
}

// Called every frame
void ACode7::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	if (c == 0)
	{
		Location.Y += 10.0f;
		SetActorLocation(Location);
		c++;
	}

	if (bPlayer != NULL)
	{
		if (bItem)
		{
			SetCode();
		}
	}

}

void ACode7::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		bItem = true;
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Set a number and hit Enter"));
		GetPlayer(OtherActor);
	}
}

void ACode7::TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Leaving the area"));
		bItem = false;
	}
}