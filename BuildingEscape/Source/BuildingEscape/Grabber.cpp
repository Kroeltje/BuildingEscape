// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Public/DrawDebugHelpers.h"

#define OUT //we define a macro that does nothing, but it helps readin our code. in this example to show that by calling a method with pass-by references, changes the variable we put in

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber active!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get the player viewpoint this tick
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewpointRotation); //OUT is a macro that does nothing but its to make our code more readable
	//UE_LOG(LogTemp, Warning, TEXT("Location: %s, Position: %s"), *PlayerViewpointLocation.ToString(), *PlayerViewpointRotation.ToString() );

	//draw a red trace in the world to visualize
	FVector LineTraceEnd = PlayerViewpointLocation + (PlayerViewpointRotation.Vector() * Reach);
	DrawDebugLine(
		GetWorld(), 
		PlayerViewpointLocation, 
		LineTraceEnd, 
		FColor(255,0,0,255), 
		false, 
		0.f,
		0.f,
		10.f
	);

	//ray-cast out to reach distance


	//evaluate what we hit



}
