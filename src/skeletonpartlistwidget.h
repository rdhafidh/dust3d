#ifndef SKELETON_PART_LIST_WIDGET_H
#define SKELETON_PART_LIST_WIDGET_H
#include <QListWidget>
#include <map>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include "skeletondocument.h"

class SkeletonPartWidget : public QWidget
{
    Q_OBJECT
signals:
    void setPartLockState(QUuid partId, bool locked);
    void setPartVisibleState(QUuid partId, bool visible);
    void setPartSubdivState(QUuid partId, bool subdived);
    void setPartDisableState(QUuid partId, bool disabled);
    void setPartXmirrorState(QUuid partId, bool mirrored);
    void setPartZmirrorState(QUuid partId, bool mirrored);
    void setPartDeformThickness(QUuid partId, float thickness);
    void setPartDeformWidth(QUuid partId, float width);
    void setPartRoundState(QUuid partId, bool rounded);
    void setPartColorState(QUuid partId, bool hasColor, QColor color);
    void setPartInverseState(QUuid partId, bool inverse);
    void movePartUp(QUuid partId);
    void movePartDown(QUuid partId);
    void movePartToTop(QUuid partId);
    void movePartToBottom(QUuid partId);
    void checkPart(QUuid partId);
    void groupOperationAdded();
    void enableBackgroundBlur();
    void disableBackgroundBlur();
public:
    SkeletonPartWidget(const SkeletonDocument *document, QUuid partId);
    void reload();
    void updatePreview();
    void updateLockButton();
    void updateVisibleButton();
    void updateSubdivButton();
    void updateDisableButton();
    void updateXmirrorButton();
    void updateZmirrorButton();
    void updateDeformButton();
    void updateRoundButton();
    void updateColorButton();
    void updateCheckedState(bool checked);
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
public slots:
    void showDeformSettingPopup(const QPoint &pos);
    void showColorSettingPopup(const QPoint &pos);
    void showContextMenu(const QPoint &pos);
private: // need initialize
    const SkeletonDocument *m_document;
    QUuid m_partId;
private:
    QLabel *m_previewLabel;
    QPushButton *m_visibleButton;
    QPushButton *m_lockButton;
    QPushButton *m_subdivButton;
    QPushButton *m_disableButton;
    QPushButton *m_xMirrorButton;
    QPushButton *m_zMirrorButton;
    QPushButton *m_deformButton;
    QPushButton *m_roundButton;
    QPushButton *m_colorButton;
    QLabel *m_nameLabel;
    QWidget *m_backgroundWidget;
private:
    void initToolButton(QPushButton *button);
    void initToolButtonWithoutFont(QPushButton *button);
    void initButton(QPushButton *button);
    void updateButton(QPushButton *button, QChar icon, bool highlighted);
    void updateAllButtons();
};

class SkeletonPartListWidget : public QListWidget
{
    Q_OBJECT
public:
    SkeletonPartListWidget(const SkeletonDocument *document, QWidget *parent);
public slots:
    void partChanged(QUuid partId);
    void partListChanged();
    void partPreviewChanged(QUuid partid);
    void partLockStateChanged(QUuid partId);
    void partVisibleStateChanged(QUuid partId);
    void partSubdivStateChanged(QUuid partId);
    void partDisableStateChanged(QUuid partId);
    void partXmirrorStateChanged(QUuid partId);
    void partDeformChanged(QUuid partId);
    void partRoundStateChanged(QUuid partId);
    void partColorStateChanged(QUuid partId);
    void partChecked(QUuid partId);
    void partUnchecked(QUuid partId);
protected:
    virtual QSize sizeHint() const;
private:
    const SkeletonDocument *m_document;
    std::map<QUuid, QListWidgetItem *> m_itemMap;
};

#endif
