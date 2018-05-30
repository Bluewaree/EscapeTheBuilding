// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "ButtonB.h"
#include "Engine.h"

// Sets default values
AButtonB::AButtonB()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Button = CreateDefaultSubobject<UBoxComponent>(TEXT("Button"));
	Button->bGenerateOverlapEvents = true;
	Button->OnComponentBeginOverlap.AddDynamic(this, &AButtonB::TriggerEnter);
	Button->OnComponentEndOverlap.AddDynamic(this, &AButtonB::TriggerExit);
	RootComponent = Button;
	SMButton = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SMButton->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AButtonB::BeginPlay()
{
	Super::BeginPlay();
	
}

void AButtonB::GetPlayer(AActor *Player)
{
	bPlayer = Cast<AMyPlayer>(Player);
}

// Called every frame
void AButtonB::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

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

void AButtonB::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Press E to interact"));
		Ready = true;
		GetPlayer(OtherActor);
	}
}

void AButtonB::TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Leaving the area"));
		Ready = false;
	}
}