// Fill out your copyright notice in the Description page of Project Settings.

#include "VvVvV_Reloaded.h"
#include "MyWebcamReader.h"

// Sets default values
AMyWebcamReader::AMyWebcamReader()
{
	//// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//// Initialize OpenCV and webcam properties
	//CameraID = 0;
	//RefreshRate = 15;
	//isStreamOpen = false;
	//VideoSize = FVector2D(0, 0);
	//ShouldResize = false;
	//ResizeDeminsions = FVector2D(320, 240);
	//stream = new cv::VideoCapture();
	//frame = new cv::Mat();
	//RefreshTimer = 1000000.0f;
}

AMyWebcamReader::~AMyWebcamReader() {
	//FMemory::Free(stream);
	//FMemory::Free(frame);
	//FMemory::Free(size);
}

// Called when the game starts or when spawned
void AMyWebcamReader::BeginPlay()
{
	Super::BeginPlay();

	//stream->open(CameraID);
	//if(stream->isOpened()) {
	//	//Initialize stream
	//	isStreamOpen = true;
	//	UpdateFrame();
	//	VideoSize = FVector2D(frame->cols, frame->rows);
	//	size = new cv::Size(ResizeDeminsions.X, ResizeDeminsions.Y);
	//	VideoTexture = UTexture2D::CreateTransient(VideoSize.X, VideoSize.Y);
	//	VideoTexture->UpdateResource();
	//	VideoUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, VideoSize.X, VideoSize.Y);

	//	//Initialize data array
	//	Data.Init(FColor(0, 0, 0, 255), VideoSize.X * VideoSize.Y);
	//}
}

// Called every frame
void AMyWebcamReader::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

	//RefreshTimer += DeltaTime;
	//if(isStreamOpen && RefreshTimer >= 1.0f / RefreshRate) {
	//	RefreshTimer -= 1.0f / RefreshRate;
	//	UpdateFrame();
	//	UpdateTexture();
	//	OnNextVideoFrame();
	//}
}
//
//void AMyWebcamReader::UpdateFrame() {
//	if(isStreamOpen) {
//		stream->read(*frame);
//		if(ShouldResize) {
//			cv::resize(*frame, *frame, *size);
//		}
//	}
//}
//
//void AMyWebcamReader::UpdateTexture() {
//	if(isStreamOpen && frame->data) {
//		//Copy Mat data to Data array
//		for(int y = 0; y < VideoSize.Y; y++) {
//			for(int x = 0; x < VideoSize.X; x++) {
//				int i = x + (y * VideoSize.X);
//				Data[i].B = frame->data[i * 3 + 0];
//				Data[i].G = frame->data[i * 3 + 1];
//				Data[i].R = frame->data[i * 3 + 2];
//			}
//		}
//
//		//Update texture 2D
//		UpdateTextureRegions(VideoTexture, (int32) 0, (uint32) 3, VideoUpdateTextureRegion, (uint32) (4 * VideoSize.X), (uint32) 4, (uint8*) Data.GetData(), false);
//	}
//}
//
//void AMyWebcamReader::UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData) {
//	if(Texture->Resource) {
//		struct FUpdateTextureRegionsData {
//			FTexture2DResource* Texture2DResource;
//			int32 MipIndex;
//			uint32 NumRegions;
//			FUpdateTextureRegion2D* Regions;
//			uint32 SrcPitch;
//			uint32 SrcBpp;
//			uint8* SrcData;
//		};
//
//		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;
//
//		RegionData->Texture2DResource = (FTexture2DResource*) Texture->Resource;
//		RegionData->MipIndex = MipIndex;
//		RegionData->NumRegions = NumRegions;
//		RegionData->Regions = Regions;
//		RegionData->SrcPitch = SrcPitch;
//		RegionData->SrcBpp = SrcBpp;
//		RegionData->SrcData = SrcData;
//
//		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
//			UpdateTextureRegionsData,
//			FUpdateTextureRegionsData*, RegionData, RegionData,
//			bool, bFreeData, bFreeData,
//			{
//				for(uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex) {
//					int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
//					if(RegionData->MipIndex >= CurrentFirstMip) {
//						RHIUpdateTexture2D(
//							RegionData->Texture2DResource->GetTexture2DRHI(),
//							RegionData->MipIndex - CurrentFirstMip,
//							RegionData->Regions[RegionIndex],
//							RegionData->SrcPitch,
//							RegionData->SrcData
//							+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
//							+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
//							);
//					}
//				}
//
//				if(bFreeData) {
//					FMemory::Free(RegionData->Regions);
//					FMemory::Free(RegionData->SrcData);
//				}
//				delete RegionData;
//			});
//	}
//}
//
//void AMyWebcamReader::OnNextVideoFrame_Implementation() {
//	// No default implementation
//}