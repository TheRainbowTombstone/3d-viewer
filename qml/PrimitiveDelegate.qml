
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    width: ListView.view.width
    height: 70
    color: index % 2 === 0 ? "#444" : "#555"

    RowLayout {
        anchors.fill: parent
        anchors.margins: 6
        spacing: 10

        Rectangle {
            width: 20; height: 20
            color: Qt.rgba(model.r, model.g, model.b, 1.0)
        }

        ColumnLayout {
            Layout.fillWidth: true
            Text { text: "Type: " + model.type; color: "white" }
            Text { text: "Crd: (" + model.x.toFixed(2) + "," + model.y.toFixed(2) + "," + model.z.toFixed(2) + ")"; color: "white" }
        }

        Button { text: "Select"; onClicked: sceneManager.pick(model.id) }
        Button { text: "Delete"; onClicked: sceneManager.delById(model.id) }
    }
}
