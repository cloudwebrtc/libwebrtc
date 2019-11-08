#include "rtc_desktop_device_impl.h" 
 

namespace libwebrtc {

	DesktopDeviceImpl::DesktopDeviceImpl()
	{ 
	} 
	 
	DesktopCaptureOptions DesktopDeviceImpl::CreateOptions()
	{
		webrtc::DesktopCaptureOptions options = webrtc::DesktopCaptureOptions::CreateDefault();
		options.set_allow_directx_capturer(true);
		return options;
	}
	/*auto options = webrtc::DesktopCaptureOptions::CreateDefault();
	 options.set_allow_directx_capturer(true);*/

	/*	����ͼ��webrtc::DesktopCapturer::CreateScreenCapturer
		����ͼ��webrtc::DesktopCapturer::CreateWindowCapturer*/

	/*����ͼ��*/
	scoped_refptr<RTCDesktopCapturer> DesktopDeviceImpl::CreateScreenCapturer(const webrtc::DesktopCaptureOptions& options)
	{   
		scoped_refptr<RTCDesktopCapturerImpl> screen_capturer =
			scoped_refptr<RTCDesktopCapturerImpl>(
				new RefCountedObject<RTCDesktopCapturerImpl>(
					webrtc::DesktopCapturer::CreateScreenCapturer(options))); 
		//scoped_refptr<DesktopCapturer> screen_capturer = scoped_refptr<DesktopCapturer>(webrtc::DesktopCapturer::CreateScreenCapturer(options).get());
		return screen_capturer;
	}
	/*Ӧ��ͼ��*/
	scoped_refptr<RTCDesktopCapturer> DesktopDeviceImpl::CreateWindowCapturer(const webrtc::DesktopCaptureOptions& options)
	{
		scoped_refptr<RTCDesktopCapturerImpl> window_capturer =
			scoped_refptr<RTCDesktopCapturerImpl>(
				new RefCountedObject<RTCDesktopCapturerImpl>(
					webrtc::DesktopCapturer::CreateWindowCapturer(options)));

		//scoped_refptr<DesktopCapturer> window_capturer = scoped_refptr<DesktopCapturer>(webrtc::DesktopCapturer::CreateWindowCapturer(options).get());
		return window_capturer;
	}
}