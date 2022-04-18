//==============================================
// Name:           Tareq Abdi
// Student Number: 123809196
// Email:          tabdi1@myseneca.ca
// Date:	       17/07/2021
//==============================================

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(const char* filename)
	{
		std::fstream file(filename);
		Song sc{};
		std::string s;

		if (!file) {
			throw std::string("ERROR: Cannot open file.\n");
		}
		else {
			while (!file.eof()) {
				std::getline(file, s);
				//
				sc.m_title = s.substr(0, 25);
				sc.m_artist = s.substr(25, 25);
				sc.m_album = s.substr(50, 25);
				sc.m_releaseYear = s.substr(75, 5);
				sc.m_length = std::stoul(s.substr(80, 5));
				sc.m_price = std::stod(s.substr(85, 5));
				//
				trim(sc.m_title);
				trim(sc.m_artist);
				trim(sc.m_album);
				trim(sc.m_releaseYear);
				//
				m_songs.push_back(sc);
			}
		}
		file.close();
	}

	std::string& SongCollection::trim(std::string& str)
	{
		bool valid = true;
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);

		while (valid)
		{
			if (str.find("  ") != std::string::npos) {
				str.erase(str.find("  "), 1);
				valid = true;
			}
			else
				valid = false;
		}
		return str;
	}

	void SongCollection::display(std::ostream& out) const
	{
		auto time = [](int sec) {
			std::string t_time;

			int hours = 0;
			int minutes = 0;

			minutes = sec / 60;
			hours = minutes / 60;

			t_time = std::to_string(hours);
			t_time += ":";
			t_time += int(minutes % 60) < 10 ? std::string("0") + std::to_string(int(minutes % 60)) : std::to_string(int(minutes % 60));
			t_time += ":";
			t_time += int(sec % 60) < 10 ? std::string("0") + std::to_string(int(sec % 60)) : std::to_string(int(sec % 60));
			//
			return t_time;
		};

		for_each(m_songs.begin(), m_songs.end(), [&](const Song& song) { out << song << std::endl; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: ";
		out << time(std::accumulate(m_songs.begin(), m_songs.end(), 0, [](int sum, const Song& sc) { return sc.m_length + sum; }));
		out << std::right << " |\n";
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		int minutes{}, seconds{};
		
		minutes = theSong.m_length / 60;
		seconds = theSong.m_length % 60;

		out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
			<< std::setw(15) << theSong.m_artist << " | "
			<< std::setw(20) << theSong.m_album << " | "
			<< std::right << std::setw(6) << theSong.m_releaseYear << " | " << minutes << ":";

		if (seconds < 10) {
			out << '0';
		}

		out << seconds << " | " 
			<< theSong.m_price << " |";

		return out;
	}

	void SongCollection::sort(const char* s) {
		std::sort(m_songs.begin(), m_songs.end(), 
			[&](Song sc_left, Song sc_right) {
				if (s == std::string("title"))
				{
					return (sc_left.m_title < sc_right.m_title);
				}
				else if (s == std::string("album")) {
					return (sc_left.m_album < sc_right.m_album);
				}
				else if (s == std::string("length")) {
					return (sc_left.m_length < sc_right.m_length);
				}
				else {
					throw std::string("Parameter doesn't match!");
				}
			});
	}

	void SongCollection::cleanAlbum() {
		auto clean = [](Song& song) {
			if (song.m_album == std::string("[None]")) {
				song.m_album.clear();
			}
		};
		std::for_each(m_songs.begin(), m_songs.end(), clean);
	}

	bool SongCollection::inCollection(const char* s) const {
		auto search = [&](const Song& song) {
			return song.m_artist == std::string(s);
		};
		//
		return std::any_of(m_songs.begin(), m_songs.end(), search);
	}

	std::list<Song> SongCollection::getSongsForArtist(const char* s) const {
		std::list<Song> m_songList(m_songs.size());
		//
		auto search = [&](const Song& song) {
			return song.m_artist == std::string(s);
		};
		//
		auto it = std::copy_if(m_songs.begin(), m_songs.end(), m_songList.begin(), search);
		//
		m_songList.resize(std::distance(m_songList.begin(), it));
		return m_songList;
	}
}