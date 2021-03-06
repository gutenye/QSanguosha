#ifndef PHOTO_H
#define PHOTO_H

#include "QSanSelectableItem.h"
#include "player.h"
#include "carditem.h"
#include "protocol.h"

#include "GeneralCardContainerUI.h"
#include <QGraphicsObject>
#include <QPixmap>
#include <QComboBox>


class ClientPlayer;
class RoleComboBox;
class QPushButton;

class Photo : public PlayerCardContainer
{
    Q_OBJECT

public:
    explicit Photo();
    const ClientPlayer *getPlayer() const;
    void speak(const QString &content);
    virtual void repaintAll();
    QList<CardItem*> removeCardItems(const QList<int> &card_id, Player::Place place);

    void showCard(int card_id);
    
    void setEmotion(const QString &emotion, bool permanent = false);
    void tremble();
    void showSkillName(const QString &skill_name);

    enum FrameType{
        S_FRAME_PLAYING,
        S_FRAME_RESPONSING,
        S_FRAME_SOS,
        S_FRAME_NO_FRAME
    };

    void setFrame(FrameType type);
    virtual QRectF boundingRect() const;
    QGraphicsItem* getMouseClickReceiver();
public slots:
    void updatePhase();
    void hideEmotion();
    void hideSkillName();
    virtual void refresh();

protected:
    inline virtual QGraphicsItem* _getEquipParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getDelayedTrickParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getAvatarParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getMarkParent() { return _m_floatingArea; }
    inline virtual QGraphicsItem* _getPhaseParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getRoleComboBoxParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getProgressBarParent() { return _m_groupMain;}
    inline virtual QGraphicsItem* _getFocusFrameParent() { return _m_groupMain; }
    inline virtual QGraphicsItem* _getDeathIconParent() { return _m_groupDeath;}
    virtual QGraphicsItem* _getPileParent() { return _m_groupMain; }
    inline virtual QString getResourceKeyName() { return QSanRoomSkin::S_SKIN_KEY_PHOTO; }
    virtual void _adjustComponentZValues();
    bool _addCardItems(QList<CardItem*> &card_items, Player::Place place);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool _m_isReadyIconVisible;
    FrameType _m_frameType;
    QGraphicsPixmapItem *_m_mainFrame;    
    QGraphicsPixmapItem *emotion_item, *_m_skillNameItem;
    QGraphicsPixmapItem *_m_focusFrame;
    QGraphicsPixmapItem *_m_onlineStatusItem;
};

#endif // PHOTOBACK_H
