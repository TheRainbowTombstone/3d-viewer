import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 1280
    height: 720
    visible: true
    title: "3d-viewer"

    RowLayout {
        anchors.fill: parent

        Sidebar {
            Layout.preferredWidth: 400
            Layout.fillHeight: true
        }

        // Сцена 3D
        SceneView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
