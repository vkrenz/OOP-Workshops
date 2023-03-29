#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include "Media.h"

namespace sdds {

	class Video : public Media {
		int m_length;
	protected:
		int get() const;
	public:
		Video();
		Video(int length);
		Video(const char* filename, const char* equipment = nullptr);
		virtual ~Video() = 0;
		Video(const Video&) = delete;
		Video& operator=(const Video&) = delete;
		bool empty() const;
		void setEmpty();
		virtual void load(std::istream& is) override = 0;
	};

}

#endif // !SDDS_VIDEO_H
