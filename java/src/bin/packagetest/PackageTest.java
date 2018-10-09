package packagetest;

class Room {
	private int roomId;
	String 		roomName;

	Room(int roomIdIn) {
		roomId = roomIdIn;
	}

	void printfRoomName(int roomId) {
		if(this.roomId == roomId)
			System.out.println(roomName);
		else
			System.out.println("connot find");
	}
}
