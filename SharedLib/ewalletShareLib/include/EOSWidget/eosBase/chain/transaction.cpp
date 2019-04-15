#include "transaction.h"
#include "eosbytewriter.h"
#include <QDateTime>

Transaction::Transaction()
{

}

void Transaction::serialize(EOSByteWriter *writer) const
{
    if (writer) {
        TransactionHeader::serialize(writer);

        SerializeCollection(context_free_action, writer);
        SerializeCollection(actions, writer);
        SerializeCollection(transaction_extensions, writer);
    }
}

QJsonValue Transaction::toJson(QString expiration, int blockNum, int blockPrefix) const
{
    QJsonObject obj = TransactionHeader::toJson().toObject();
	QJsonArray ctxFreeActionsArr, actionArr, transaction_extensions;
    for (const auto& ctx : context_free_action) {
        ctxFreeActionsArr.append(ctx.toJson());
    }

    for (const auto& a : actions) {
        actionArr.append(a.toJson());
    }

    obj.insert("context_free_actions", ctxFreeActionsArr);
	obj.insert("transaction_extensions", transaction_extensions);
    obj.insert("actions", actionArr);

	QDateTime date = QDateTime::fromString(expiration, Qt::ISODate);
	date = date.addSecs(30+ date.offsetFromUtc());

	obj.insert("expiration", QJsonValue(date.toString(Qt::ISODate)));
	obj.insert("ref_block_num", blockNum);
	obj.insert("ref_block_prefix", blockPrefix);
	obj.insert("max_net_usage_words",TransactionHeader::getMax_net_usage_words());
	obj.insert("max_cpu_usage_ms", TransactionHeader::getMax_cpu_usage_ms());
	obj.insert("delay_sec", TransactionHeader::getDelay_seconds());

    return QJsonValue(obj);
}

void Transaction::fromJson(const QJsonValue &value)
{
    QJsonObject obj = value.toObject();
    if (obj.isEmpty()) {
        return;
    }

    QJsonArray ctxFreeActionsArr = obj.value("context_free_actions").toArray();
    if (!ctxFreeActionsArr.isEmpty()) {
        for (int i = 0; i < ctxFreeActionsArr.size(); ++i) {
            Action action;
            action.fromJson(ctxFreeActionsArr.at(i));
            context_free_action.push_back(action);
        }
    }

    QJsonArray actionsArr = obj.value("actions").toArray();
    if (!actionsArr.isEmpty()) {
        for (int i = 0; i < actionsArr.size(); ++i) {
            Action action;
            action.fromJson(actionsArr.at(i));
            actions.push_back(action);
        }
    }

    TransactionHeader::fromJson(value);
}

void Transaction::addAction(const Action& action)
{
    actions.push_back(action);
}

void Transaction::setActions(const std::vector<Action> &actions)
{
    this->actions = actions;
}
