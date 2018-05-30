// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "ButtonA.h"
#include "Engine.h"


AButtonA::AButtonA()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	Button = CreateDefaultSubobject<UBoxComponent>(TEXT("Door"));
	Button->bGenerateOverlapEvents = true;
	Button->OnComponentBeginOverlap.AddDynamic(this, &AButtonA::TriggerEnter);
	Button->OnComponentEndOverlap.AddDynamic(this, &AButtonA::TriggerExit);
	RootComponent = Button;
	SMButton = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	SMButton->AttachTo(RootComponent);
}


void AButtonA::BeginPlay()
{
	Super::BeginPlay();
	
}

void AButtonA::GetPlayer(AActor * Player)
{
	bPlayer = Cast<AMyPlayer>(Player);
}


void AButtonA::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector Location = GetActorLocation();

	if (c == 0)
	{
		Location.X -=80.0f;
		SetActorLocation(Location);
		c++;
	}
	else if(c==1)
	{
		Location.X += 810.0f;
		SetActorLocation(Location);
		c++;
	}

	if (bPlayer != NULL)
	{

		if (bItem && bPlayer->Interaction)
		{
			
			if (c2==0)
			{
				Click = 1;
				GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, TEXT("Interaction has been made"));
			}
			else
			{			
				Click = 2;
				GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, TEXT("Interaction has been made"));
			}
		}
		else if (bItem && !bPlayer->Interaction && Click == 1)
		{
			c2 = 1;
		}
	}

}

void AButtonA::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		bItem = true;
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Hit E to interact with the Button"));
		GetPlayer(OtherActor);
	}
}

void AButtonA::TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, TEXT("Leaving the area"));
		bItem = false;
		
	}
}