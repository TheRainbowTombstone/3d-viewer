import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    color: "#333"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        RowLayout {
            spacing: 10
            Button { text: "Add object"; onClicked: addDialog.open() }
            Button { text: "Clear"; onClicked: sceneManager.clearAll() }
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: sceneManager ? sceneManager.model : []

            delegate: PrimitiveDelegate {}
        }

        AddObjectDialog { id: addDialog }
    }
}
