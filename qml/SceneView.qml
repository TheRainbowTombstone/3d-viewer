import QtQuick
import QtQuick3D
import QtQuick3D.Helpers

View3D {
    id: view3d
    focus: true
    Component.onCompleted: forceActiveFocus()

    environment: SceneEnvironment {
        clearColor: "skyblue"
        backgroundMode: SceneEnvironment.Color
    }

    Node {
        id: sceneRoot

        Node {
            id: cameraOrigin
            PerspectiveCamera {
                id: camera
                position: Qt.vector3d(0, 200, 600)
                eulerRotation.x: -15
                fieldOfView: 45
            }
        }

        DirectionalLight { eulerRotation.x: -45; eulerRotation.y: -20; color: "white" }
    }

    OrbitCameraController {
        anchors.fill: parent
        origin: cameraOrigin
        camera: camera
        mouseEnabled: true
        panEnabled: true
    }

    Connections {
        target: sceneManager

        function onShapeAdded(p) {
            var obj = Qt.createQmlObject(
                'import QtQuick3D; Model { objectName: "shape"; property var uid: -1; property var originalColor: Qt.rgba(1,1,1,1) }',
                sceneRoot
            )
            obj.uid = p.id
            obj.originalColor = Qt.rgba(p.r, p.g, p.b, 1.0)
            obj.source = "#Cube"
            obj.position = Qt.vector3d(p.posX, p.posY, p.posZ)
            obj.scale = Qt.vector3d(p.sizeX, p.sizeY, p.sizeZ)

            var mat = Qt.createQmlObject('import QtQuick3D; PrincipledMaterial {}', obj)
            mat.baseColor = obj.originalColor
            obj.materials = [mat]
        }

        function onShapePicked(id) {
            for (var i = 0; i < sceneRoot.children.length; i++) {
                var o = sceneRoot.children[i]
                if (o.objectName === "shape") {
                    o.materials[0].baseColor = (o.uid === id) ? Qt.rgba(1,1,0,1) : o.originalColor
                }
            }
        }

        function onShapeRemoved(id) {
            for (var i = sceneRoot.children.length - 1; i >= 0; i--) {
                var o = sceneRoot.children[i]
                if (o.objectName === "shape" && o.uid === id) {
                    o.destroy()
                }
            }
        }
    }
}
