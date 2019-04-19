#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <modsecurity/rule_message.h>
#include <modsecurity/rule.h>
#include <modsecurity/transaction.h>

namespace py = pybind11;

using modsecurity::Rule;
using modsecurity::RuleMessage;
using modsecurity::Transaction;

void init_rule_message(py::module &m)
{
    py::class_<RuleMessage>(m, "RuleMessage")
        .def(py::init<Rule *, Transaction *>())
        .def("log", (std::string (RuleMessage::*) ()) &RuleMessage::log)
        .def("log", (std::string (RuleMessage::*) (int)) &RuleMessage::log)
        .def("log", (std::string (RuleMessage::*) (int, int)) &RuleMessage::log)
        .def("errorLog", &RuleMessage::errorLog)
        // .def_static("slog", (std::string (RuleMessage::*) (const RuleMessage *, int, int)) &RuleMessage::log)
        // .def_static("slog", (std::string (RuleMessage::*) (const RuleMessage *, int)) &RuleMessage::log)
        // .def_static("slog", (std::string (RuleMessage::*) (const RuleMessage *)) &RuleMessage::log)
        .def_static("_details", (std::string (*) (const RuleMessage *)) &RuleMessage::_details)
        .def_static("_errorLogTail", (std::string (*) (const RuleMessage *)) &RuleMessage::_errorLogTail)
        .def_readwrite("m_accuracy", &RuleMessage::m_accuracy)
        .def_readwrite("m_clientIpAddress", &RuleMessage::m_clientIpAddress)
        .def_readwrite("m_data", &RuleMessage::m_data)
        .def_readwrite("m_id", &RuleMessage::m_id)
        .def_readwrite("m_isDisruptive", &RuleMessage::m_isDisruptive)
        .def_readwrite("m_match", &RuleMessage::m_match)
        .def_readwrite("m_maturity", &RuleMessage::m_maturity)
        .def_readwrite("m_message", &RuleMessage::m_message)
        .def_readwrite("m_noAuditLog", &RuleMessage::m_noAuditLog)
        .def_readwrite("m_phase", &RuleMessage::m_phase)
        .def_readwrite("m_reference", &RuleMessage::m_reference)
        .def_readwrite("m_rev", &RuleMessage::m_rev)
        .def_readwrite("m_rule", &RuleMessage::m_rule)
        .def_readwrite("m_ruleFile", &RuleMessage::m_ruleFile)
        .def_readwrite("m_ruleId", &RuleMessage::m_ruleId)
        .def_readwrite("m_ruleLine", &RuleMessage::m_ruleLine)
        .def_readwrite("m_saveMessage", &RuleMessage::m_saveMessage)
        .def_readwrite("m_serverIpAddress", &RuleMessage::m_serverIpAddress)
        .def_readwrite("m_severity", &RuleMessage::m_severity)
        .def_readwrite("m_uriNoQueryStringDecoded", &RuleMessage::m_uriNoQueryStringDecoded)
        .def_readwrite("m_ver", &RuleMessage::m_ver)
        .def_readwrite("m_tags", &RuleMessage::m_tags)
        ;
}
