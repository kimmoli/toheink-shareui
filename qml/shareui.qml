import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.TransferEngine 1.0

ShareDialog 
{
    id: root
    allowedOrientations: Orientation.Portrait

    property int viewWidth: root.isPortrait ? Screen.width : Screen.width / 2
    property variant jids: []

    property string path: source

    canAccept: true

    onAccepted: 
	{
		shareItem.start()
    }

    SailfishShare 
	{
        id: shareItem
        source: root.path
        metadataStripped: true
        serviceId: root.methodId
        userData: {"description": "Toheink"}
    }

	Column
	{
		Label
		{
			text: root.path
		}
	}
}
