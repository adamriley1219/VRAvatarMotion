// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueCharacter.h"


// Sets default values
AMyBlueCharacter::AMyBlueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyBlueCharacter::BeginPlay()
{
	Super::BeginPlay();
	//#if UR_BUILD_DEBUG
		if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO WORLD!"));
	//#endif
}

// Called every frame
void AMyBlueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalcMotionCap();
	//USkeletalMeshComponent mesh = Actor->FindComponentByClass<USkeletalMeshComponent>();

}

// Called to bind functionality to input
void AMyBlueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AMyBlueCharacter::isMoving()
{
	//if (this->GetCharacterMovement->Velocity.SizeSquared() < 5)
	//{
	//	return true;
	//}
	return false;
}

void AMyBlueCharacter::CalcMotionCap()
{
	//std::vector<USceneComponent> sceneComps;
	//FString fstring = FindComponentByClass<USceneComponent>()->GetName();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO WORLD!"));
	for (UActorComponent *const component : GetComponents())
	{
		if (component->GetName().Equals("Scene"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			scenePos = temp->GetComponentTransform();
		}
		else if (component->GetName().Equals("HipTracker"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Hip = temp->GetComponentTransform();
			FRotator theRot;
			theRot.Yaw = 90; // for left hip
			Hip.SetRotation(Hip.GetRotation()*FQuat(theRot));

			FVector pos = Hip.GetLocation();
			FVector perp = temp->GetForwardVector();
			pos[0] -= perp[0] * 18;
			pos[1] -= perp[1] * 18;
			pos[2] -= perp[2] * 18;
			Hip.SetLocation(pos);
		}
		else if (component->GetName().Equals("Camera"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Head = temp->GetComponentTransform();
		}
		else if (component->GetName().Equals("MotionController_l"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			LHandTrack = temp->GetComponentTransform();
		}
		else if (component->GetName().Equals("MotionController_r"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			RHandTrack = temp->GetComponentTransform();
		}
	}
	
	//std::ofstream outFile;
	//outFile.open("../../../../../../Users/adamr/Desktop/test.csv");
	//outFile << "Frame,Hip Trans X,Hip Trans Y,Hip Trans Z,Hip Rot X,Hip Rot Y,Hip Rot Z,Head Trans X,Head Trans Y,Head Trans Z,Head Rot X,Head Rot Y,Head Rot Z,LeftHand Trans X,LeftHand Trans Y,LeftHand Trans Z,LeftHand Rot X,LeftHand Rot Y,LeftHand Rot Z,RightHand Trans X,RightHand Trans Y,RightHand Trans Z,RightHand Rot X,RightHand Rot Y,RightHand Rot Z,Scene Trans X,Scene Trans Y,Scene Trans Z,Scene Rot X,Scene Rot Y,Scene Rot Z" << std::endl
	//	<< frameCounter  << "," 
	//	<< Hip.GetLocation().X << "," << Hip.GetLocation().Y << "," << Hip.GetLocation().Z << "," << Hip.GetRotation().X << "," << Hip.GetRotation().Y << "," << Hip.GetRotation().Z << ","
	//	<< Head.GetLocation().X << "," << Head.GetLocation().Y << "," << Head.GetLocation().Z << "," << Head.GetRotation().X << "," << Head.GetRotation().Y << "," << Head.GetRotation().Z << ","
	//	<< LHandTrack.GetLocation().X << "," << LHandTrack.GetLocation().Y << "," << LHandTrack.GetLocation().Z << "," << LHandTrack.GetRotation().X << "," << LHandTrack.GetRotation().Y << "," << LHandTrack.GetRotation().Z << ","
	//	<< RHandTrack.GetLocation().X << "," << RHandTrack.GetLocation().Y << "," << RHandTrack.GetLocation().Z << "," << RHandTrack.GetRotation().X << "," << RHandTrack.GetRotation().Y << "," << RHandTrack.GetRotation().Z << ","
	//	<< scenePos.GetLocation().X << "," << scenePos.GetLocation().Y << "," << scenePos.GetLocation().Z << "," << scenePos.GetRotation().X << "," << scenePos.GetRotation().Y << "," << scenePos.GetRotation().Z << std::endl;
	//	//<< "Location of Scene:	" << TCHAR_TO_UTF8(*scenePos.ToString()) << std::endl;
	//outFile.close();

	Spine; // .SetComponents(FQuat Rotation, FVector Translation, FVector Scale)
	Spine1;
	Spine2;
	Neck;
	LShoulder;
	LArm;
	LForeArm;
	RShoulder;
	RArm;
	RForeArm;
	LUpLeg;
	LLeg;
	LFoot;
	RUpLeg;
	RLeg;
	RFoot;
}

void AMyBlueCharacter::TakeSnapshot()
{
	if (outFile.is_open())
	{
		frameCounter++;
		outFile
			<< frameCounter  << "," 
			<< Hip.GetLocation().X << "," << Hip.GetLocation().Y << "," << Hip.GetLocation().Z << "," << Hip.GetRotation().X << "," << Hip.GetRotation().Y << "," << Hip.GetRotation().Z << ","
			<< Head.GetLocation().X << "," << Head.GetLocation().Y << "," << Head.GetLocation().Z << "," << Head.GetRotation().X << "," << Head.GetRotation().Y << "," << Head.GetRotation().Z << ","
			<< LHandTrack.GetLocation().X << "," << LHandTrack.GetLocation().Y << "," << LHandTrack.GetLocation().Z << "," << LHandTrack.GetRotation().X << "," << LHandTrack.GetRotation().Y << "," << LHandTrack.GetRotation().Z << ","
			<< RHandTrack.GetLocation().X << "," << RHandTrack.GetLocation().Y << "," << RHandTrack.GetLocation().Z << "," << RHandTrack.GetRotation().X << "," << RHandTrack.GetRotation().Y << "," << RHandTrack.GetRotation().Z << ","
			<< scenePos.GetLocation().X << "," << scenePos.GetLocation().Y << "," << scenePos.GetLocation().Z << "," << scenePos.GetRotation().X << "," << scenePos.GetRotation().Y << "," << scenePos.GetRotation().Z << std::endl;
	}
}

void AMyBlueCharacter::StartRecording()
{
	if (!outFile.is_open())
	{
		frameCounter = 0;
		scenesCaptured++;
		std::stringstream ss;
		ss << "../../../../../../Users/adamr/Desktop/MotionCaptured_" << scenesCaptured << ".csv";
		outFile.open(ss.str());
		outFile << "Frame,Hip Trans X,Hip Trans Y,Hip Trans Z,Hip Rot X,Hip Rot Y,Hip Rot Z,Head Trans X,Head Trans Y,Head Trans Z,Head Rot X,Head Rot Y,Head Rot Z,LeftHand Trans X,LeftHand Trans Y,LeftHand Trans Z,LeftHand Rot X,LeftHand Rot Y,LeftHand Rot Z,RightHand Trans X,RightHand Trans Y,RightHand Trans Z,RightHand Rot X,RightHand Rot Y,RightHand Rot Z,Scene Trans X,Scene Trans Y,Scene Trans Z,Scene Rot X,Scene Rot Y,Scene Rot Z" << std::endl;
	}
};

void AMyBlueCharacter::EndRecording()
{
	if (outFile.is_open())
	{
		outFile.close();
	}
};
