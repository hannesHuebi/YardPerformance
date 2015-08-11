import QtQuick 2.0
import Ubuntu.Components 1.1
import YardPerformace 1.0

/*!
    \brief MainView with a Label and Button elements.
*/


MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    id: mainView
    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "yardperformanceapp.hannes"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(75)

    PageStack {
        id: pageStack
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        Component.onCompleted: pageStack.push(root)

        Page {
            id: root

            title: i18n.tr("YardPerformace")

            ParseCSV {
                id: parser

                Component.onCompleted: {
                    listElements.append({"name": "Bsp", "value": parser.BspString})
                    listElements.append({"name": "Awa", "value": parser.AwaString})
                    listElements.append({"name": "%VMG", "value": parser.PVmgString})
                    listElements.append({"name": "VMG", "value": parser.VmgString})
                    listElements.append({"name": "AwaOpt", "value": parser.AwaOptString})
                }

                function refreshGridView(){
                    parser.ReReadValues();
                    listElements.clear();
                    listElements.append({"name": "Bsp", "value": parser.BspString})
                    listElements.append({"name": "Awa", "value": parser.AwaString})
                    listElements.append({"name": "%VMG", "value": parser.PVmgString})
                    listElements.append({"name": "VMG", "value": parser.VmgString})
                    listElements.append({"name": "AwaOpt", "value": parser.AwaOptString})
                }
            }
            Component{
                id: delegateItem
                Item {
                    x: 5
                    width: gridView1.cellWidth - units.gu(2)
                    height: gridView1.cellHeight - units.gu(2)
                    Rectangle {
                        width: parent.width
                        height: parent.height
                        border.color: "black"
                        border.width: units.gu(0.2)
                        radius: units.gu(1)
                        color: mainView.backgroundColor
                        anchors.horizontalCenter: parent.horizontalCenter
                        Text {
                            y: units.gu(0.2)
                            text: name
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.bold: false
                            font.italic: true
                            font.pixelSize: (parent.height/2) - units.gu(3)
                        }

                        Text {
                            y: parent.height / 2
                            text: value
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.bold: true
                            font.pixelSize: (parent.height/2) - units.gu(3)
                        }
                    }
                }
            }
            GridView {
                id: gridView1
                width: parent.width
                height: parent.height
                delegate: delegateItem
                cellHeight: units.gu(12)
                cellWidth: units.gu(17)
                model: ListModel {
                    id: listElements
                }

            }
//            Button {
//                text: "Settings"
//                onClicked: pageStack.push(settings)
//            }

            Timer {
                interval: 1000; running: true; repeat: true
                onTriggered: {
                    if (root.active)
                    parser.refreshGridView();
                }
            }
        }
        Page{
            id: settings

            title: i18n.tr("Settings")

        }
    }



}
