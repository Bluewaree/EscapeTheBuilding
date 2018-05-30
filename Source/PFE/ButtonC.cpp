// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "ButtonC.h"
#include "Engine.h"

// Sets default values
AButtonC::AButtonC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Button = CreateDefaultSubobject<UBoxComponent>(TEXT("Button"));
	Button->bGenerateOverlapEvents = true;
	Button->OnComponentBeginOverlap.AddDynamic(this, &AButtonC::TriggerEnter);
	Button->OnComponentEndOverlap.AddDynamic(this, &AButtonC::TriggerExit);
	RootComponent = Button;
	SMButton = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SMButton->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AButtonC::BeginPlay()
{
	Super::BeginPlay();

}

void AButtonC::GetPlayer(AActor *Player)
{
	bPlayer = Cast<AMyPlayer>(Player);
}

// Called every frame
void AButtonC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	if (c == 0)
	{
		Location.X += 10;
		SetActorLocation(Location);
		c++;
	}

	if (bPlayer != NULL)
	{
		if (Ready && bPlayer->Interaction)
		{
			Active = true;
		}
	}
}

void AButtonC::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Press E to interact"));
		Ready = true;
		GetPlayer(OtherActor);
	}
}

void AButtonC::TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Leaving the area"));
		Ready = false;
	}
}