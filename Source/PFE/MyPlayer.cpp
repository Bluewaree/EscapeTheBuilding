// Fill out your copyright notice in the Description page of Project Settings.

#include "PFE.h"
#include "MyPlayer.h"


AMyPlayer::AMyPlayer()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GetCapsuleComponent()->InitCapsuleSize(40.f, 150.f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 200.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	UCameraComponent *FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMyPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	InputComponent->BindAction("0", IE_Pressed, this, &AMyPlayer::Press0);
	InputComponent->BindAction("1", IE_Pressed, this, &AMyPlayer::Press1);
	InputComponent->BindAction("2", IE_Pressed, this, &AMyPlayer::Press2);
	InputComponent->BindAction("3", IE_Pressed, this, &AMyPlayer::Press3);
	InputComponent->BindAction("4", IE_Pressed, this, &AMyPlayer::Press4);
	InputComponent->BindAction("5", IE_Pressed, this, &AMyPlayer::Press5);
	InputComponent->BindAction("6", IE_Pressed, this, &AMyPlayer::Press6);
	InputComponent->BindAction("7", IE_Pressed, this, &AMyPlayer::Press7);
	InputComponent->BindAction("8", IE_Pressed, this, &AMyPlayer::Press8);
	InputComponent->BindAction("9", IE_Pressed, this, &AMyPlayer::Press9);
	InputComponent->BindAction("Enter", IE_Pressed, this, &AMyPlayer::BeginEnter);
	InputComponent->BindAction("Enter", IE_Released, this, &AMyPlayer::EndEnter);
	InputComponent->BindAction("E", IE_Pressed, this, &AMyPlayer::InteractBegin);
	InputComponent->BindAction("E", IE_Released, this, &AMyPlayer::InteractEnd);

	InputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);


	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMyPlayer::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMyPlayer::LookUpAtRate);


}


void AMyPlayer::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayer::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayer::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMyPlayer::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}


void AMyPlayer::Press0()
{
	numberTest += FString("0");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press1()
{
	numberTest += FString("1");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press2()
{
	numberTest += FString("2");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press3()
{
	numberTest += FString("3");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press4()
{
	numberTest += FString("4");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press5()
{
	numberTest += FString("5");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press6()
{
	numberTest += FString("6");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press7()
{
	numberTest += FString("7");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press8()
{
	numberTest += FString("8");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::Press9()
{
	numberTest += FString("9");
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *numberTest));
}

void AMyPlayer::InteractBegin()
{
	Interaction = true;
}

void AMyPlayer::InteractEnd()
{
	Interaction = false;
}

void AMyPlayer::BeginEnter()
{
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, TEXT("Enter"));
	number = numberTest;
	numberTest = FString("");
	ready = true;
}

void AMyPlayer::EndEnter()
{
	ready = false;
}

