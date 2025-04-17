# Playlist Application - ReadMe

## Overview
This Playlist Application is a console-based C++ program that allows users to manage a playlist of songs. It uses a doubly linked list data structure to store and manipulate song information. Users can add songs, remove songs by their unique ID, display the playlist, display it in reverse order, and search for a specific song by its ID.

## Features
1. **Add a New Song**:
   - Add a song to the playlist with an ID, title, and artist.
2. **Remove a Song by ID**:
   - Remove a song from the playlist using its unique ID.
3. **Display Playlist**:
   - Display the entire playlist in the order of insertion.
4. **Display Playlist in Reverse Order**:
   - Display the playlist in reverse order.
5. **Search a Song by ID**:
   - Search for a specific song in the playlist using its ID.
6. **Exit Program**:
   - Exit the application.

## How to Run the Program
1. Ensure you have a C++ compiler (e.g., g++).
2. Compile the program using the command:
   ```bash
   g++ -o playlist_app main.cpp
   ```
3. Run the compiled program:
   ```bash
   ./playlist_app
   ```

## Implementation Details
- The program uses a doubly linked list to maintain the playlist.
- Each node in the list contains song information (ID, title, artist) and pointers to the next and previous nodes.
- Input validation ensures that song titles and artist names contain only alphabetic characters.

## Usage
Follow the on-screen menu to interact with the application. Enter the number corresponding to your desired action.
