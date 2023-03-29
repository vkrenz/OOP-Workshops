#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include "Video.h"

namespace sdds {

	class VRVideo : public Video {
		char* m_equipment;
	public:
		VRVideo();
		VRVideo(const char* filename, const char* equipment);
		VRVideo(const VRVideo&) = delete;
		VRVideo& operator=(const VRVideo&) = delete;
		virtual ~VRVideo();
		virtual void load(std::istream& is);
		virtual std::ostream& play(std::ostream& os) const;
	};

}

#endif // !SDDS_VRVIDEO_H