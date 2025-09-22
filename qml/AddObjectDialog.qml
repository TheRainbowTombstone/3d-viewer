
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: dialog
    title: "Add object"
    modal: true
    standardButtons: Dialog.Ok | Dialog.Cancel

    contentItem: ColumnLayout {
        spacing: 10
        anchors.margins: 10

        ComboBox { id: objectType; Layout.fillWidth: true; model: ["Cube"] }

        RowLayout { spacing: 5; Label { text: "Width:" } SpinBox { id: w; from: 1; to: 20; value: 1 } }
        RowLayout { spacing: 5; Label { text: "Height:" } SpinBox { id: h; from: 1; to: 20; value: 1 } }
        RowLayout { spacing: 5; Label { text: "Depth:" } SpinBox { id: d; from: 1; to: 20; value: 1 } }
        RowLayout { spacing: 5; Label { text: "Quantity:" } SpinBox { id: count; from: 1; to: 50; value: 1 } }
    }

    onAccepted: sceneManager.addShapes(objectType.currentText, w.value, h.value, d.value, count.value)
}
