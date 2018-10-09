package reflectTest;

class Room {
	private String roomId;
	private String roomName;
	private String beStationId;
	private String beRegionId;

	Room() {
	}
	Room(String roomIdIn) {
		roomId = roomIdIn;
	}
	Room(String roomIdIn, String roomNameIn,
		String beStationIdIn, String beRegionIdIn) {
		roomId 		= roomIdIn;
		roomName    = roomNameIn;
		beStationId = beStationIdIn;
		beRegionId  = beRegionIdIn;
	}

	String getRoomId() {
		return roomId;
	}
	void setRoomId(String roomId) {
		this.roomId = roomId;
	}
}

public class ReflectTest {
	public static void main(String[] args) {
		//first
		Room room = new Room("1353443");
		Class roomClass = room.getClass();

		//second
		Class roomClass1 = Room.class;

		//third
		try {
			Class roomClass2 = Class.forName("Room");
		}
		catch (ClassNotFoundException ex) {
			ex.printStackTrace();
		}
	}
}

	
