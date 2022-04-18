//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	       17/07/2021
//==============================================

#pragma once
#include <vector>
#include <list>

namespace sdds {
	struct Song {
		std::string m_artist{}, m_title{}, m_album{}, m_releaseYear{};
		size_t m_length{};
		double m_price{};
	};

	class SongCollection {
	public:
		SongCollection() = default;
		~SongCollection() = default;
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void cleanAlbum();
		bool inCollection(const char * s) const;
		void sort(const char* s);
		std::list<Song> getSongsForArtist(const char* s) const;
	private:
		std::string& trim(std::string& s);
		std::vector<Song> m_songs{};
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}